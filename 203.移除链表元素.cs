/*
 * @lc app=leetcode.cn id=203 lang=csharp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution
{
    public ListNode RemoveElements(ListNode head, int val)
    {
        while (head != null && head.val == val)
            head = head.next;

        if (head != null)
        {
            for (ListNode i = head; i != null && i.next != null; i = i.next)
            {
                while (i.next != null && i.next.val == val)
                    i.next = i.next.next;
            }
        }

        return head;
    }
}
// @lc code=end

