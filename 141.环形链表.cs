/*
 * @lc app=leetcode.cn id=141 lang=csharp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution
{
    //private Dictionary<ListNode, bool> dict = new();
    public bool HasCycle(ListNode head)
    {
        // ListNode temp = head;
        // while (temp != null)
        // {
        //     if (dict.ContainsKey(temp)) { return true; }
        //     else { dict.Add(temp, true); }
        //     temp = temp.next;
        // }
        // return false;
        if (head == null || head.next == null)
        {
            return false;
        }

        ListNode quickNode = head.next;
        ListNode slowNode = head;
        bool timer = false;

        while (quickNode != null)
        {
            if (quickNode == slowNode)
            {
                return true;
            }

            quickNode = quickNode.next;
            if (timer)
            {
                slowNode = slowNode.next;
            }

            timer ^= true;
        }

        return false;
    }
}
// @lc code=end

