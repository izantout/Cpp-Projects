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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listNodeLength = 1;
        int index = 1;
        ListNode* lengthCounter = head;
        ListNode* current = head;
        // Check if the ListNode is null or contains 1 element
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        // Go through the ListNode to know the length
        while(lengthCounter->next){
            listNodeLength++;
            lengthCounter = lengthCounter->next;
        }
        cout << "The length is: " << listNodeLength << endl;
        // Go through the ListNode to remove the nth last node
        while(current->next){
            // check if length is the same as n (remove the head)
            if (n == listNodeLength) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
                return head;
            }
            // check if we are 1 before the nth last node
            if((n+index) == listNodeLength){
                // set a temp pointer equal to the node we want to delete
                ListNode* temp = current->next;
                // change the current->next to the one after the node to be deleted
                current->next = current->next->next;
                // delete the temp node
                delete temp;
                // break out of loop 
                return head;
            }
            // update the index
            index++;
            // go to next node
            current = current->next;
        }
        // return head
        return head;
    }
};
