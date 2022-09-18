/*
 * @lc app=leetcode.cn id=21 lang=csharp
 *
 * [21] 合并两个有序链表
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
    public ListNode MergeTwoLists(ListNode l1, ListNode l2)
    {
        ListNode ansHead = new ListNode(0, null);
        ListNode p = new ListNode(0, null);

        ansHead = p;

        while (l1 != null && l2 != null)
        {
            if (l1.val < l2.val)
            {
                p.next = l1; p = l1;
                l1 = l1.next;
            }
            else
            {
                p.next = l2; p = l2;
                l2 = l2.next;
            }
        }

        p.next = (l1 == null) ? l2 : l1;

        return ansHead.next;
    }
}
// @lc code=end

