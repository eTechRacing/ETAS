from math import sqrt, cos, sin, pi, acos, atan, tan


# Position in 3d space
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



