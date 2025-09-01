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
class Solution {
public:

    ListNode* swapNodes(ListNode* previous,ListNode* current)
    {
        // if current node is null then we have reached the end
        // if next node is null then length is odd, and last node cannot be swapped
        if(current == nullptr || current->next == nullptr)
        {
            return nullptr;
        }

        // next node becomes current node by having previous point to it
        // current node points to two nodes ahead so it can become next
        // current node becomes next by having next point to it
        ListNode* next = current->next;
        current->next = next->next;
        next->next = current;
        // if previous node is not empty then point to next
        if(previous != nullptr)
        {
            previous->next = next;
        }
        return next;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        head = swapNodes(nullptr,head);
        ListNode* currentNode = head;
        while(true)
        {
            // slide by two nodes to swap
            currentNode = swapNodes(currentNode->next,currentNode->next->next);
            if(currentNode == nullptr)
            {
                break;
            }
        }
        return head;
    }
};
