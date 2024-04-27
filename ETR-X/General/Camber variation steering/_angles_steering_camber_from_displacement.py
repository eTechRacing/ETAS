from math import sqrt, cos, sin, pi, acos, atan, tan
from _functions import *


############################################################################
###            VARIABLES FROM SOLIDWORKS ASSEMBLY (Left Wheel)           ###
############################################################################
p1 = vect3D(    0.669938,   -589.112170,    143.724569) # Rotation Centre of Steering Knuckle at the Tie-Rod Plane
p2 = vect3D(    -46.938867, -599.420072,    146.213420) # Position of outer end of Tie-Rod at steering 0º
p3 = vect3D(    22.737584,  -545.680055,    141.333743) # Random point in the same plane
a = vect3D(    -48.678386,  -200.000000,    167.677085) # Initial point of the inner end of Tie-Rod at steering 0º
b = vect3D(     0.0,        1.0,            0.0)        # Director vector for the movement of the Rack-Axis (Positive is to the Right) 
total_rack_displacement = 27                            # mm that the Rack-Axis is allowed to move in ONE way

###################################################
###                 AUTOMATIC                   ###
###################################################
p13 = p3-p1 # Vector from random point to centre of Steering Knuckle at the Tie-Rod Plane
p12 = p2-p1 # Vector that indicates the direction of the wheel (Steering Knuckle Center to Tie-Rod Outer End )
radius = p12.modulus() # Rotation Radius of the Tie-Rod outer end around the Rotation Centre of the Steering Knuckle at the Tie-Rod Plane

# Plane Ax + By + Cz + D = 0
norm = vect_product(p13, p12) # Normal of the Tie-Rod Plane (A, B, C)
D = -scalar_product( norm, p1) # D component of the Tie-Rod Plane
norm = norm.normalize() # Normalizing the direction of the normal


def projected_angles_from_displacement_rad(displacement, toe_angle_rad) -> float:
    v1 = p12.normalize()
    v2 = vect_product(v1, norm)
    v2 = v2.normalize()
    # radius = 48.775461
    old_tierod_circle = projected_2D_circle( p1, radius, v1, v2)

    r1 = old_tierod_circle.calc_point(toe_angle_rad)

    global d
    d = (r1-a).modulus()
    
    v1 = (r1-p1).normalize()
    v2 = vect_product(v1,norm)
    v2 = v2.normalize()
    tierod_circle = projected_2D_circle( p1, radius, v1, v2)


    disp_real = 0
    phi = pi/180*displacement
    Q = tierod_circle.calc_point(phi) # Punt anclatge tierod a la mangueta donat un cert angle


    counter = 0
    while(abs(disp_real - displacement) > 0.001 and counter < 1000):
        counter += 1
        poly_a = scalar_product(b, b)
        poly_b = 2*(scalar_product(a, b) - scalar_product(Q, b))
        poly_c = scalar_product(Q, Q) - 2*scalar_product(Q, a) + scalar_product(a, a) - d**2

        if( poly_b**2 - 4*poly_a*poly_c < 0 ):
            print("No viable solution")
            Q = tierod_circle.calc_point(0)
        else:
            disp_real = (-poly_b+sqrt(poly_b**2 - 4*poly_a*poly_c))/(2*poly_a) #Només hi ha una solució (comprovat)
            phi = phi + (displacement-disp_real)*0.01
            Q = tierod_circle.calc_point(phi)

    # Calcular angulo ground
    vec1 = v1
    vec2 = (Q-p1)
    try:
        ang = acos(scalar_product(vec1, vec2)/(vec1.modulus()*vec2.modulus())) * sign(displacement) 
    except:
        ang = 0
    ang += toe_angle_rad

    angulo_plano_tierod_vs_suelo = acos( scalar_product(norm, vect3D(0,0,1))/(norm.modulus()*vect3D(0,0,1).modulus()) )
    projected_ang = atan( tan(ang) * cos(angulo_plano_tierod_vs_suelo) )

    values = [projected_ang]

    # Calcular Camber
    camber_general = vector_angle_rad(norm, vect3D(0,0,1))
    angulo_plano_frontal_rueda_y_plano_angulo = vector_angle_rad( vect_product(norm, vect3D(0,0,1)), vec2)
    camber_projected_front_of_wheel = atan( tan(camber_general) * cos(angulo_plano_frontal_rueda_y_plano_angulo) )

    values.append(camber_projected_front_of_wheel)

    # Calcular SideAngle
    vec3 = vect_product(vec2, norm)
    angulo_plano_lateral_rueda_y_plano_side = vector_angle_rad( vect_product(norm, vect3D(0,0,1)), vec3 )
    angulo_lateral = atan( tan(camber_general) * cos(angulo_plano_lateral_rueda_y_plano_side) )

    values.append(-angulo_lateral)


    values.append(Q)
    
    return values


print("---=== Steering Calculations ===---")
print("===================================")
print("-> Steering Right is Positive")
print("-> Toe Inward is Positive ")
print("-> Camber Outside is Positive")
print("-> Caster To Front is Positive")
print("===================================")

res_step = 0
while(res_step <= 0.):
    res_step = float(input("-> Displacement Resolution (mm): "))

print(f"-> Maximum rack displacement: %3.1f" %total_rack_displacement)
print(f"-> Total datapoints: %d" %int(total_rack_displacement/res_step * 2 + 1))


toe_angle_deg = None
while(toe_angle_deg == None ):
    try:
        toe_angle_deg = float(input("-> Input toe Angle (Deg): "))
    except:
        pass

# toe_angle_deg = -2
# print( f"-> Input toe Angle (Deg): %2.1" %toe_angle_deg)


m = projected_angles_from_displacement_rad(-total_rack_displacement, toe_angle_deg*pi/180)
# print(m[3])
# print("Camber Angle (Deg): ", vector_angle_rad(norm, vect3D(0,0,1.))*180/pi)
print(f"-> Tie-rod distance: %6.3f" %d)
print(f"-> Shims (mm): %2.1f" %((d-400)+3))
# print("-> Pletinas (1 per mm): ", int(round((d-400) + 3)) )

displacements = []
steering = []
camber = []
lateral = []

minimum = -total_rack_displacement
maximum = total_rack_displacement
i = minimum

print("-> Generating data")
m = projected_angles_from_displacement_rad(i, toe_angle_deg*pi/180)
displacements.append(i)
steering.append(m[0]*180/pi)
camber.append(m[1]*180/pi)
lateral.append(m[2]*180/pi)
while( i < maximum ):
    i += res_step
    m = projected_angles_from_displacement_rad(i, toe_angle_deg*pi/180)
    displacements.append(i)
    steering.append(m[0]*180/pi)
    camber.append(m[1]*180/pi)
    lateral.append(m[2]*180/pi)
    
steering_r = [-steering[-i] for i in range(1, len(steering)+1)]

print("-> Data Generated\a")
print("===================================")


display_data = str(input("-> Display data? [Y/n]: ")).lower()
if( display_data[0] == 'y'):
    print("|===================|==============================|==================|==================|")
    print("| Displacement (mm) | Projected Wheel Rotation (º) | Camber Angle (º) | Caster Angle (º) |")
    print("|===================|==============================|==================|==================|")
    for i in range(len(displacements)):
        print(f"|        %10.6f |" %displacements[i], end='')
        print(f"%12.7f                  |" %steering[i], end='')
        print(f"%12.7f      |" %camber[i], end='')
        print(f"%12.7f      |" %lateral[i])
    print("|===================|==============================|==================|==================|")
else:
    pass

print("-> Generating Diagrams")


import matplotlib.pyplot as plt

str_steering = "SteeringAtGround_VS_Input_Toe_" + f"%2.1f"%toe_angle_deg + ".png"
str_camber = "Camber_VS_Input_Toe_" + f"%2.1f"%toe_angle_deg + ".png"
str_lateral = "Lateral_VS_Input_Toe_" + f"%2.1f"%toe_angle_deg + ".png"
str_excel = "Steering_Input_Data_Toe_" + f"%2.1f"%toe_angle_deg + ".xlsx"


########################################################################################
# Steer at Ground VS Input Steer
########################################################################################
plt.figure(figsize=(10,6))
plt.suptitle( f"Steer at Ground VS Input Steer [Both Wheels] [Toe = %2.1fº]" %toe_angle_deg, fontsize='16')
plt.title("Right is Positive", y=1, fontsize='12')
plt.xlabel( "Steering Displacement (mm)" )
plt.ylabel( "Steering at Ground (º)" )

big_x_grid = [*range(-100,101,5)]
big_y_grid = [*range(-100,101,5)]
plt.xticks(big_x_grid)
plt.yticks(big_y_grid)

plt.xlim(( min(displacements)-5 , max(displacements)+5 ))
plt.ylim(( min( min(steering), min(steering_r) )-5 , max( max(steering), max(steering_r) )+5))

plt.axhline(y=0, color='gray', linestyle=':')
plt.axvline(x=0, color='gray', linestyle=':')
plt.grid(visible=True ,linestyle='dotted', color='gray')


plt.plot( displacements, steering, color='blue', label='Left Tyre')
plt.plot( displacements, steering_r, color='red', label='Right Tyre' )
plt.legend()
plt.savefig(str_steering, dpi=300)
# plt.show()



########################################################################################
# Camber VS Input Steer
########################################################################################
plt.figure(figsize=(10,6))
plt.suptitle( f"Camber VS Input Steer [Both Wheels] [Toe = %2.1fº]" %toe_angle_deg, fontsize='16')
plt.title("Outside is Positive", y=1, fontsize='12')
plt.xlabel( "Steering Displacement (mm)" )
plt.ylabel( "Camber Angle (º)" )

big_y_grid = [*range(-100,101,5)]
big_y_grid = [big_y_grid[i]/10 for i in range(len(big_y_grid))]
plt.xticks(big_x_grid)
plt.yticks(big_y_grid)

plt.xlim(( min(displacements)-5 , max(displacements)+5 ))
plt.ylim((-4, 3))

plt.axhline(y=0, color='gray', linestyle=':')
plt.axvline(x=0, color='gray', linestyle=':')
plt.grid(visible=True ,linestyle='dotted', color='gray')

plt.plot( displacements, camber, color='red' )

plt.savefig(str_camber, dpi=300)



########################################################################################
# Lateral Angle VS Input Steer
########################################################################################
plt.figure(figsize=(10,6))
plt.suptitle( f"Lateral Angle VS Input Steer [Both Wheels] [Toe = %2.1fº]" %toe_angle_deg, fontsize='16')
plt.title("Front is Positve", y=1, fontsize='12')
plt.xlabel( "Steering Displacement (mm)" )
plt.ylabel( "Lateral Angle (º)" )

big_y_grid = [*range(-100,100,5)]
big_y_grid = [big_y_grid[i]/10 for i in range(len(big_y_grid))]
plt.xticks(big_x_grid)
plt.yticks(big_y_grid)

plt.xlim(( min(displacements)-5 , max(displacements)+5 ))
plt.ylim((-1, 5))

plt.axhline(y=0, color='gray', linestyle=':')
plt.axvline(x=0, color='gray', linestyle=':')
plt.grid(visible=True ,linestyle='dotted', color='gray')

plt.plot( displacements, lateral, color='green' )
plt.savefig(str_lateral, dpi=300)

print("-> Diagrams Generated\a")
print("===================================")

########################################################################################
# Excel
########################################################################################
print("-> Exporting Values to Excel File")


import xlsxwriter
workbook = xlsxwriter.Workbook(str_excel)
worksheet = workbook.add_worksheet()

worksheet.write( 0, 0, "Toe Angle [º]" )
worksheet.write( 1, 0, toe_angle_deg)
worksheet.write( 0, 1, "Steering Input [mm]" )
worksheet.write( 0, 2, "Left Steering Angle [º]" )
worksheet.write( 0, 3, "Right Steering Angle [º]" )
worksheet.write( 0, 4, "Camber Angle [º]" )
worksheet.write( 0, 5, "Caster Angle [º]" )

for i in range(len(displacements)):
    worksheet.write( i+1, 1, displacements[i] )
    worksheet.write( i+1, 2, steering[i] )
    worksheet.write( i+1, 3, steering_r[i] )
    worksheet.write( i+1, 4, camber[i] )
    worksheet.write( i+1, 5, lateral[i] )
workbook.close()

print("-> Values Copied to Excel File\a")
print("===================================")
input("Press anything to exit.")