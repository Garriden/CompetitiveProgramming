	bool hasCycle(ListNode *head) {
        if(head == nullptr or head->next == nullptr) return false;

        unordered_set<ListNode*> set;
        int val = -1;
        while(!set.count(head)) {
            set.insert(head);
            head = head->next;
            if(head == nullptr) {
                return false;
            }
        }
        return true;
    }


    bool hasCycleTwoPointers(ListNode *head) {  
        if(head == nullptr or head->next == nullptr) return false;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr) {

            slow = slow->next;
            
            fast = fast->next;
            if(fast == nullptr) return false;
            fast = fast->next;

            if(slow == fast) return true;
        }

        return false;
    }
