/*
 * @lc app=leetcode.cn id=146 lang=csharp
 *
 * [146] LRU 缓存
 */

// @lc code=start
public class LNode
{
    public int Key { get; private set; }
    public int Value { get; private set; }
    public LNode? Next { get; set; }
    public LNode? Prev { get; set; }

    public LNode(int key, int value)
    {
        Key = key;
        Value = value;
        Next = null;
        Prev = null;
    }

    public void Update(int value)
    {
        Value = value;
    }

    public string Info()
    {
        return "LNode : Value = " + Value + ", Key = " + Key;
    }
}
public class LinkedList
{
    public LNode Head { get; private set; }
    public LNode Rear { get; private set; }
    public int Count { get; private set; }

    /// <summary>
    /// 用一个LNode节点初始化LinkedList 
    /// </summary>
    /// <param name="node">初始节点</param>
    public LinkedList(LNode node)
    {
        Head = node;
        Rear = node;
        Count = 1;
    }

    /// <summary>
    /// 添加1：头插法
    /// 新节点插入到头节点前
    /// </summary>
    /// <param name="newNode">待插入节点</param>
    public void InsertAtHead(LNode newNode)
    {
        newNode.Next = Head;
        Head.Prev = newNode;
        Head = newNode;
        Count++;
    }

    /// <summary>
    /// 添加2：尾插法
    /// 新节点插入到尾节点后
    /// </summary>
    /// <param name="newNode">待插入节点</param>
    public void InsertAtRear(LNode newNode)
    {
        Rear.Next = newNode;
        newNode.Prev = Rear;
        Rear = newNode;
        Count++;
    }

    /// <summary>
    /// 添加3：在特定位置插入
    /// 新节点插入到指定位置
    /// </summary>
    /// <param name="newNode">待插入节点</param>
    /// <param name="pos">待插入位置</param>
    public void InsertAtPos(LNode newNode, int pos)
    {
        if (pos == Count) { InsertAtRear(newNode); return; }

        LNode? baseNode = GetNodeAt(pos);
        if (baseNode != null)
        {
            InsertBeforNode(newNode, baseNode);
        }
    }

    /// <summary>
    /// 添加4：在指定节点后插入
    /// 新节点插入到指定节点后
    /// </summary>
    /// <param name="newNode">待插入节点</param>
    /// <param name="baseNode">指定节点</param>
    public void InsertAfterNode(LNode newNode, LNode baseNode)
    {
        if (baseNode.Next != null)
        {
            baseNode.Next.Prev = newNode;
            newNode.Next = baseNode.Next;
        }

        baseNode.Next = newNode;
        newNode.Prev = baseNode;

        if (baseNode == Rear) { Rear = newNode; }

        Count++;
    }

    /// <summary>
    /// 添加5：在指定节点前插入
    /// 新节点插入到指定节点前
    /// </summary>
    /// <param name="newNode">待插入节点</param>
    /// <param name="baseNode">指定节点</param>
    public void InsertBeforNode(LNode newNode, LNode baseNode)
    {
        if (baseNode.Prev != null)
        {
            baseNode.Prev.Next = newNode;
            newNode.Prev = baseNode.Prev;
        }

        baseNode.Prev = newNode;
        newNode.Next = baseNode;

        if (baseNode == Head) { Head = newNode; }

        Count++;
    }

    /// <summary>
    /// 删除1：删除头节点
    /// </summary>
    public void RemoveHead()
    {
        if (Head.Next != null)
        {
            // TODO: 释放内存
            Head = Head.Next;
            Head.Prev.Next = null;
            Head.Prev = null;
            Count--;
        }
    }

    /// <summary>
    /// 删除2：删除尾节点
    /// </summary>
    public void RemoveRear()
    {
        if (Rear.Prev != null)
        {
            // TODO: 释放内存
            Rear = Rear.Prev;
            Rear.Next.Prev = null;
            Rear.Next = null;
            Count--;
        }
    }

    /// <summary>
    /// 删除3：删除指定位置节点
    /// </summary>
    /// <param name="pos">指定位置</param>
    public void RemoveAt(int pos)
    {
        if (Count == 1) { return; }

        LNode? tempNode = GetNodeAt(pos);
        if (tempNode != null)
        {
            RemoveNode(tempNode);
        }
    }

    /// <summary>
    /// 删除4: 删除指定节点
    /// </summary>
    /// <param name="node">指定节点</param>
    public void RemoveNode(LNode node)
    {
        if (Count == 1) { return; }

        if (node == Head) { RemoveHead(); return; }

        if (node == Rear) { RemoveRear(); return; }

        if (node.Next != null && node.Prev != null)
        {
            node.Prev.Next = node.Next;
            node.Next.Prev = node.Prev;
        }
        else if (node.Prev != null)
        {
            node.Prev.Next = null;
        }
        else if (node.Next != null)
        {
            node.Next.Prev = null;
        }
        Count--;
    }

    /// <summary>
    /// 更改：修改指定位置节点Value
    /// </summary>
    /// <param name="pos">指定位置</param>
    /// <param name="value">传入要修改为的value</param>
    public void UpdatePos(int pos, int value)
    {
        LNode? tempNode = GetNodeAt(pos);
        if (tempNode != null)
        {
            tempNode.Update(value);
        }
    }

    /// <summary>
    /// 查询：获取指定位置节点
    /// </summary>
    /// <param name="pos">指定位置</param>
    /// <returns></returns>
    public LNode? GetNodeAt(int pos)
    {
        if (pos < 0 || pos >= Count) { return null; }

        int tempCounter = 0;
        if (pos > (Count >> 1)) // 从后往前找
        {
            LNode tempNode = Rear;
            while (tempNode != null)
            {
                if (tempCounter == Count - 1 - pos)
                {
                    return tempNode;
                }
                tempCounter++;
            }
        }
        else // 从前往后找
        {
            LNode tempNode = Head;
            while (tempNode != null)
            {
                if (tempCounter == pos)
                {
                    return tempNode;
                }
                tempCounter++;
            }
        }

        return null;
    }

    /// <summary>
    /// 将指定节点移动至链表头
    /// </summary>
    /// <param name="node">指定节点</param>
    public void LetNodeToHead(LNode node)
    {
        //LNode tempNode = new(node.Key, node.Value);

        if (Count == 1) { return; }
        RemoveNode(node);
        InsertAtHead(node);
    }

    public void PrintDebugInfo()
    {
        Console.WriteLine(Count);
        for (LNode? node = Head; node != null; node = node.Next)
        {
            Console.WriteLine(node.Info());
        }
        Console.WriteLine("");
    }
}
public class LRUCache
{
    private int capacity;
    private LinkedList list;
    private Dictionary<int, LNode> dict = new();
    public LRUCache(int capacity)
    {
        this.capacity = capacity;
    }

    public int Get(int key)
    {
        // TODO
        if (dict.ContainsKey(key))
        {
            LNode node = dict[key];
            list.LetNodeToHead(node);
            return node.Value;
        }
        else
        {
            return -1;
        }
    }

    public void Put(int key, int value)
    {
        if (list == null)
        {
            LNode node = new(key, value);
            list = new(node);
            dict.Add(key, node);
        }
        else
        {
            if (dict.ContainsKey(key))
            {
                LNode node = dict[key];
                if (key == 9 && value == 12)
                {
                    Console.Write(node.Value + " " + node.Next.Value + " " + node.Prev.Value);
                    list.PrintDebugInfo();
                }
                node.Update(value);
                if (key == 9 && value == 12)
                {
                    Console.Write(node.Value + " " + node.Next.Value + " " + node.Prev.Value);
                    list.PrintDebugInfo();
                }//nodeDict[key].val = value;
                list.LetNodeToHead(node);
            }
            else
            {
                LNode node = new(key, value);
                list.InsertAtHead(node);
                dict.Add(key, node);

                if (list.Count > capacity)
                {
                    dict.Remove(list.Rear.Key);
                    list.RemoveRear();

                }
            }
        }

        //list.PrintDebugInfo();
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
// @lc code=end
