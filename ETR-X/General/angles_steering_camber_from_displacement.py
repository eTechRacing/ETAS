from math import sqrt, cos, sin, pi, acos, atan, tan

class vect3D:
    def __init__(self, x:float, y:float, z:float):
        self.x = x
        self.y = y
        self.z = z

    def normalize(self):
        mod = sqrt( self.x*self.x + self.y*self.y + self.z*self.z )
        self.x /= mod
        self.y /= mod
        self.z /= mod
        return self
    
    def modulus(self) -> float:
        return sqrt( self.x*self.x + self.y*self.y + self.z*self.z )

    def __str__(self) -> str:
        return f"x: %15.6f\ty: %15.6f\tz: %15.6f" %(self.x, self.y, self.z)
    
    def __add__(self, o):
        return vect3D( self.x+o.x, self.y+o.y, self.z+o.z)
    
    def __sub__(self, o):
        return vect3D( self.x-o.x, self.y-o.y, self.z-o.z)
    
    def __mul__(self, o:float):
        return vect3D(self.x*o, self.y*o, self.z*o)
    def rotate_in_plane(self, plane):
        pass


class projected_2D_circle:
    def __init__(self, center:vect3D, radius:float, v1:vect3D, v2:vect3D):
        self.center = center
        self.radius = radius
        self.v1 = v1
        self.v2 = v2

    def calc_point(self, phi) -> vect3D:
        return self.center + self.v1*cos(phi)*self.radius + self.v2*sin(phi)*self.radius


def vect_product(one:vect3D, two:vect3D):
    return vect3D(
        two.z*one.y - two.y*one.z,
        two.x*one.z - two.z*one.x,
        two.y*one.x - two.x*one.y,
    )
def scalar_product(one:vect3D, two:vect3D):
    return one.x*two.x + one.y*two.y + one.z*two.z
def sign(x):
    if(x > 0): return 1
    else: return -1
def vector_angle_rad(one: vect3D, two:vect3D):
    return acos( scalar_product(one, two)/(one.modulus()*two.modulus()) )




# Punts del pla del tierod
p1 = vect3D(    0.669938,   -589.112170,    143.724569) # Centre de rotació del tierod
p2 = vect3D(    -46.938867, -599.420072,    146.213420) # Punt inicial (angle 0) de la roda
p3 = vect3D(    22.737584,  -545.680055,    141.333743) # Punt random del mateix pla

p13 = vect3D(   p3.x-p1.x,  p3.y-p1.y,  p3.z-p1.z)
p12 = vect3D(   p2.x-p1.x,  p2.y-p1.y,  p2.z-p1.z)

# Plano Ax + By + Cz + D = 0
norm = vect_product(p13, p12) # Componentes A, B, C del plano
D = -scalar_product( norm, p1) # Componente D del plano
norm = norm.normalize()


def projected_angles_from_displacement_rad(displacement, toe_angle_rad) -> float:
    a = vect3D(    -48.678386,  -200.000000,    167.677085) # Punt inici de la recta 3D del rack-axis
    b = vect3D(     0.0,        1.0,            0.0)        # Vector director de la recta 3D rack-axis

    v1 = p12.normalize()
    v2 = vect_product(v1, norm)
    v2 = v2.normalize()
    radius = 48.775461
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
    while(abs(disp_real - displacement) > 0.01 and counter < 100):
        counter += 1
        poly_a = scalar_product(b, b)
        poly_b = 2*scalar_product(a, b) - 2*scalar_product(Q, b)
        poly_c = scalar_product(Q, Q) - 2*scalar_product(Q, a) + scalar_product(a, a) - d**2

        if( poly_b**2 - 4*poly_a*poly_c < 0 ):
            print("No viable solution")
            Q = tierod_circle.calc_point(0)
        else:
            disp_real = (-poly_b+sqrt(poly_b**2 - 4*poly_a*poly_c))/(2*poly_a) #Només hi ha una solució (comprovat)
            phi = phi + (displacement-disp_real)*0.01
            Q = tierod_circle.calc_point(phi)

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

    camber_general = vector_angle_rad(norm, vect3D(0,0,1))
    angulo_plano_frontal_rueda_y_plano_angulo = vector_angle_rad( vect_product(norm, vect3D(0,0,1)), vec2)
    camber_projected_front_of_wheel = atan( tan(camber_general) * cos(angulo_plano_frontal_rueda_y_plano_angulo) )

    values.append(camber_projected_front_of_wheel)
    
    return values




print("---=== Left Wheel ===---")
print("-> Steering left is negative")
toe_angle_deg = float(input("-> Input toe Angle (Deg): "))
m = projected_angles_from_displacement_rad(0, toe_angle_deg*pi/180)
# print("Camber Angle (Deg): ", vector_angle_rad(norm, vect3D(0,0,1.))*180/pi)

print("-> Tie-rod distance: ", d)
print("-> mm de pletinas: ", (d-400)+3)
print("-> Pletinas (1 per mm): ", int(round((d-400) + 3)) )
print("|===================|==============================|==================|")
print("| Displacement (mm) | Projected Wheel Rotation (º) | Camber Angle (º) |")
print("|===================|==============================|==================|")
for i in range(-270, 275, 5):
    # print("------------------------")
    print(f"|             %5.1f |" %(i/10), end='')
    m = projected_angles_from_displacement_rad(i/10, toe_angle_deg*pi/180)
    print(f"%12.7f                  |" %(m[0]*180/pi), end='')
    print(f"%12.7f      |" %(m[1]*180/pi))
print("|===================|==============================|==================|")

