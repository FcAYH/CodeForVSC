/*
 * @lc app=leetcode.cn id=206 lang=csharp
 *
 * [206] 反转链表
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
    // Iteration
    public ListNode ReverseList(ListNode head)
    {
        if (head == null)
            return null;
        if (head.next == null)
            return head;

        ListNode prev = head;
        head = head.next;
        prev.next = null;

        while (head != null)
        {
            ListNode temp = head;
            head = head.next;
            temp.next = prev;
            prev = temp;
        }

        return prev;
    }
}
// @lc code=end

