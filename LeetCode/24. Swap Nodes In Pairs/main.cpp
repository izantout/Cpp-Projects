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
 /*
 O(n)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        int i = 0;
        while(current != nullptr){
            i++;
            current = current->next;
        }
        cout << "Length is: " << i << endl;
        current = head;
        while(current != nullptr){
            cout << "I am at: " << current->val << endl;
            if(current->next != nullptr){
                int temp = current->val;
                cout << "Current Val is: " << current->val << endl;
                current->val = current->next->val;
                current->next->val = temp;
                cout << "After change, current val is: " << current->val << endl;
                cout << "After change, next val is: " << current->next->val << endl;
                current = current->next->next;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* nextPair = head->next->next;
        ListNode* newHead = head->next;
        newHead->next = head;
        head->next = swapPairs(nextPair);

        return newHead;
    }
};
