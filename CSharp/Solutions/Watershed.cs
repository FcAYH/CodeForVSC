namespace Solutions;

public class Watershed
{
    public int[,] Solve(double[,] dist)
    {
        int n = dist.GetLength(0);
        int m = dist.GetLength(1);
        int[,] region = new int[n, m];
        int currentLabel = 0;
        int[,] markers = new int[n, m];

        // Find local minima and mark them as markers
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                bool isMinimum = true;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (dist[x, y] < dist[i, j])
                        {
                            isMinimum = false;
                            break;
                        }
                    }
                    if (!isMinimum) break;
                }
                if (isMinimum)
                {
                    markers[i, j] = ++currentLabel;
                }
            }
        }

        // Apply watershed algorithm
        while (true)
        {
            // Find the minimum distance between markers and unassigned points
            double minDist = double.MaxValue;
            int x = -1, y = -1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (markers[i, j] != 0) continue;
                    if (dist[i, j] < minDist)
                    {
                        minDist = dist[i, j];
                        x = i;
                        y = j;
                    }
                }
            }
            if (x == -1 || y == -1) break; // No more unassigned points

            // Assign the point to the nearest marker
            int nearestMarker = 0;
            double nearestDist = double.MaxValue;
            for (int i = x - 1; i <= x + 1; i++)
            {
                for (int j = y - 1; j <= y + 1; j++)
                {
                    if (i < 0 || i >= n || j < 0 || j >= m) continue;
                    if (markers[i, j] == 0) continue;
                    double distToMarker = dist[i, j] + Math.Sqrt((i - x) * (i - x) + (j - y) * (j - y));
                    if (distToMarker < nearestDist)
                    {
                        nearestDist = distToMarker;
                        nearestMarker = markers[i, j];
                    }
                }
            }
            markers[x, y] = nearestMarker;
        }

        // Assign regions based on markers
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                region[i, j] = markers[i, j];
            }
        }

        return region;
    }
}
/*
 double[,] dist = new double[,]
        {
            { 1, 2, 1, 3, 4 },
            { 2, 1, 3, 2, 1 },
            { 1, 3, 2, 1, 2 },
            { 4, 1, 3, 2, 1 },
            { 3, 2, 1, 2, 3 }
        };

        Watershed watershed = new Watershed();

        int[,] region = watershed.Solve(dist);

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                Console.Write(region[i, j] + " ");
            }
            Console.WriteLine();
        }
*/
