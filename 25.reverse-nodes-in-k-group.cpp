/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {

        if (head != NULL || head->next != NULL)
        {
            return NULL;
        }

        ListNode *prev = NULL;
        ListNode *current = head;
        ListNode *next = NULL;

        int count = 0;
        // Reverse k-nodes
        while (current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        // Recursion
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
// @lc code=end
