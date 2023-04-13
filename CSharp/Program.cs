using Solutions;
using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using System.Diagnostics;

public class Entry
{
    private static float CircumCircle(float ax, float az, float bx, float bz, float cx, float cz, out float[] center)
    {
        const float EPS = 1e-6f;
        center = new float[] { 0, 0, 0 };

        float[] ab = { bx - ax, 0, bz - az };
        float[] ac = { cx - ax, 0, cz - az };

        float radius = -1f;
        float area2 = Area2(ab, ac);
        if (Math.Abs(area2) > EPS)
        {
            float abLength_squared = Dot2(ab, ab);
            float acLength_squared = Dot2(ac, ac);

            center[0] = (acLength_squared * ab[2] - abLength_squared * ac[2]) / (2 * area2);
            center[2] = (abLength_squared * ac[0] - acLength_squared * ab[0]) / (2 * area2);
            radius = (float)Math.Sqrt(center[0] * center[0] + center[2] * center[2]);

            center[0] += ax;
            center[2] += az;
        }

        return radius;
    }

    public static float Dot2(float[] vec1, float[] vec2)
    {
        return vec1[0] * vec2[0] + vec1[2] * vec2[2];
    }
    public static float Area2(float[] ab, float[] ac)
    {
        return ab[2] * ac[0] - ac[2] * ab[0];
    }

    public static void Main()
    {
        float ax = 1, az = 0;
        float bx = -1, bz = 0;
        float cx = 0, cz = 2;

        float[] center;
        float radius = CircumCircle(ax, az, bx, bz, cx, cz, out center);

        Console.WriteLine("Radius: {0}, Center: ({1}, {2}, {3})", radius, center[0], center[1], center[2]);
    }
}

/*
6,0,8,2,1,5
0 1 2 3 4 5

0 1 2 5 6 8
1 4 3 5 0 2

[9,8,1,0,1,9,4,0,4,1]

2 2 1
0 1 2

1 2 2
2 0 1
2 1 0
*/
