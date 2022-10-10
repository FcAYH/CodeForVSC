using System;
using System.Collections.Generic;

public class Entry
{
    public static void Main()
    {
        int numberCount = 20;
        int[] number = new int[numberCount];

        Random rand = new Random(DateTime.Now.Millisecond);
        for (int i = 0; i < numberCount; i++)
        {
            number[i] = rand.Next() % 1000;
        }

        number.SortAsHeap();

        foreach (var element in number)
        {
            Console.Write(element + " ");
        }
        Console.WriteLine("");
    }
}

public static class ExtensionMethod
{
    /// <summary>
    /// 利用堆排序，对数组进行排序(降序排)
    /// </summary>
    public static void SortAsHeap(this int[] array)
    {
        /*
        思路：
            首先堆可以用数组去表示，组下标从0开始，则若根节点为i，左子节点为2i+1，右子节点为2i+2
            假设现在用数组A存堆，堆大小为n，即数组A的0，n-1存了堆
            现在我们对一个堆插入操作时，会将新增的数，放在A[n]，然后慢慢将该数上浮到正确的位置
            那么将一个大小为length的无序数组，转换成对的格式的方式即：
            for循环枚举0到length-1，当枚举到i时，即理解成现在的堆为A[0]~A[i-1]，而新插入的数为A[i]
            如此即可将无序数组A，转换成堆的形式

            而如何输出有序序列呢？
            对于一个堆，想要有序输出，我们会每次删除堆顶，将堆顶输出，直到堆空。
            则我们可以每次将堆顶和堆的最后一个元素交换，然后维护一下堆，直到堆空，
            此时我们就得到了一个有序序列，
            如果我们是维护的小根堆，此时数组A[0]~A[length-1]就是一个降序序列
            反之则是升序序列。
        */
        // 将数组生成堆
        for (int i = 0; i < array.Length; i++)
        {
            // 从前往后，将每个数放到正确的位置上
            int current = i;
            bool flag = false;

            while (current != 0 && !flag)
            {
                int parent = (current - 1) >> 1;
                if (array[parent] > array[current])
                {
                    Swap(ref array[parent], ref array[current]);
                }
                else flag = true;

                current = (current - 1) >> 1;
            }
        }

        // 将堆还原成数组
        int last = array.Length - 1;
        while (last != 0)
        {
            Swap(ref array[last], ref array[0]);

            int current = 0;
            bool flag = false;

            while (current < last && !flag)
            {
                int left = (current << 1 | 1);
                int right = (current << 1) + 2;
                if (left < last && array[left] < array[current]
                    && (right >= last || right < last && array[left] < array[right]))
                {
                    Swap(ref array[left], ref array[current]);
                    current = left;
                }
                else if (right < last && array[right] < array[current])
                {
                    Swap(ref array[right], ref array[current]);
                    current = right;
                }
                else flag = true;
            }

            last--;
        }
    }

    private static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
}
