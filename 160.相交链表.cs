/*
 * @lc app=leetcode.cn id=160 lang=csharp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution
{
    public ListNode GetIntersectionNode(ListNode headA, ListNode headB)
    {
        // Dictionary<ListNode, int> set = new Dictionary<ListNode, int>();

        // for (ListNode i = headA; i != null; i = i.next)
        //     set.Add(i, 1);

        // for (ListNode i = headB; i != null; i = i.next)
        //     if (set.ContainsKey(i) == true)
        //         return i;

        // return null;

        ListNode pA = headA, pB = headB;

        while (pA != pB)
        {
            pA = (pA == null) ? headB : pA.next;
            pB = (pB == null) ? headA : pB.next;
        }

        return pA;
    }
}
// @lc code=end

