using System;
using System.Collections.Generic;

namespace Solutions;

public class TreeNode
{
    public char Value;
    public Dictionary<char, TreeNode> Children;
    public TreeNode FailPointer;
    public int WordEnd;

    public TreeNode(char value)
    {
        Value = value;
        Children = new Dictionary<char, TreeNode>();
        FailPointer = null;
        WordEnd = 0;
    }
}

public class ACAutomaton
{
    public string[] KeyWords { get; private set; }
    private TreeNode _trie;

    public ACAutomaton(string[] keyWords)
    {
        KeyWords = keyWords;
        InitializeTrie();
    }

    private void InitializeTrie()
    {
        // 构建trie树
        _trie = new TreeNode('+');
        for (int i = 0; i < KeyWords.Length; i++)
        {
            var word = KeyWords[i];
            TreeNode parent = _trie;
            foreach (var character in word)
            {
                if (!parent.Children.ContainsKey(character))
                {
                    TreeNode child = new TreeNode(character);
                    parent.Children.Add(child.Value, child);
                }

                parent = parent.Children[character];
            }
            parent.WordEnd = i + 1;
        }

        // 初始化fail指针
        Queue<TreeNode> nodeQ = new();
        foreach (var child in _trie.Children.Values)
        {
            child.FailPointer = _trie;
            nodeQ.Enqueue(child);
        }

        while (nodeQ.Count != 0)
        {
            TreeNode current = nodeQ.Dequeue();
            foreach (var child in current.Children.Values)
            {
                TreeNode fail = current.FailPointer;
                while (fail != null)
                {
                    if (fail.Children.ContainsKey(child.Value))
                    {
                        child.FailPointer = fail.Children[child.Value];
                        break;
                    }
                    fail = fail.FailPointer;
                }
                if (fail == null)
                    child.FailPointer = _trie;

                nodeQ.Enqueue(child);
            }
        }
    }

    public int[] Query(string input)
    {
        int[] queryResult = new int[KeyWords.Length];

        TreeNode current = _trie;
        foreach (char character in input)
        {
            if (current.Children.ContainsKey(character))
            {
                current = current.Children[character];
            }
            else
            {
                current = current.FailPointer;
            }
            if (current == null) current = _trie;

            if (current.WordEnd != 0)
                queryResult[current.WordEnd - 1]++;
        }

        return queryResult;
    }
}
