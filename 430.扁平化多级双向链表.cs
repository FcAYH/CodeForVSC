/*
 * @lc app=leetcode.cn id=430 lang=csharp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
public class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
}
*/

public class Solution
{
    private Stack<Node> stack;
    private void dfs(Node poi, int isChild)
    {
        if (poi == null)
            return;

        if (poi.child != null)
        {
            stack.Push(poi.next);
            poi.next = poi.child;
            poi.next.prev = poi;
            poi.child = null;

            dfs(poi.next, isChild + 1);
        }
        else
        {
            if (poi.next != null)
                dfs(poi.next, isChild);
            else
            {
                if (isChild != 0)
                {
                    int layerSub = 0;
                    while (stack.Count > 0 && poi.next == null)
                    {
                        poi.next = stack.Pop();
                        layerSub++;
                    }

                    if (poi.next != null)
                        poi.next.prev = poi;

                    dfs(poi.next, isChild - layerSub);
                }
            }
        }
    }

    public Node Flatten(Node head)
    {
        if (head == null)
            return null;

        stack = new Stack<Node>();

        dfs(head, 0);

        return head;
    }
}
// @lc code=end

