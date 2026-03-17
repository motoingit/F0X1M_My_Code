

// Interface
interface Shape {
    float PI = 3.14f;
    float volume();
}
// ✔ Cone
class Cone implements Shape {
    int height, radius;

    Cone(int h, int r) {
        height = h;
        radius = r;
    }

    public float volume() {
        return (1/3.0f) * PI * radius * radius * height;
    }
}

// ✔ Hemisphere
class Hemisphere implements Shape {
    int radius;

    Hemisphere(int r) {
        radius = r;
    }

    public float volume() {
        return (2/3.0f) * PI * (float)Math.pow(radius, 3);
    }
}

// ✔ Cylinder
class Cylinder implements Shape {
    int height, radius;

    Cylinder(int h, int r) {
        height = h;
        radius = r;
    }

    public float volume() {
        return PI * radius * radius * height;
    }
}

// ✔ Main
public class j13_Interface {
    public static void main(String[] args) {
        Shape s1 = new Cone(10, 10);
        Shape s2 = new Hemisphere(10);
        Shape s3 = new Cylinder(10, 10);

        System.out.println(s1.volume());
        System.out.println(s2.volume());
        System.out.println(s3.volume());
    }
}
