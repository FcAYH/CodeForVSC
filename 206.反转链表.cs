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
    private ListNode RecursionReverseList(ListNode nowNode, ListNode prevNode)
    {
        if (nowNode == null)
            return prevNode;

        ListNode temp = nowNode.next;
        nowNode.next = prevNode;

        return RecursionReverseList(temp, nowNode);
    }

    // recursion
    public ListNode ReverseList(ListNode head)
    {
        if (head == null || head.next == null)
            return head;

        ListNode temp = head.next;
        head.next = null;
        return RecursionReverseList(temp, head);
    }
}
// @lc code=end

