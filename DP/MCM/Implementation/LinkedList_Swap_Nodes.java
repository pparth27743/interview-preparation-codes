public class Main {
    public static void main(String[] args) {
        LL list = new LL();
        
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);
        
        list.printLL();
        list.swapNodes(1,5);
        list.printLL();
    }
}

class Node{
    int value;
    Node next;
    
    Node(int value) {
        this.value = value;
        next = null;
    }
}

class LL{
    Node head;
    
    LL() { head = null; }
    
    public void add(int value) {
        Node node = new Node(value);
        if(head == null)
            head = node;
        else {
            Node curr = head;
            while(curr.next != null)
                curr = curr.next;
            curr.next = node;
        }
    }
    
    public void printLL() {
        Node curr = head;
        while(curr != null){
            System.out.print(curr.value + " ");
            curr = curr.next;
        }
        System.out.println();
    }
    
    public void swapNodes(int x, int y) {
        if(x == y)
            return;
        
        Node prevX = null, currX = head;
        while(currX != null && currX.value != x){
            prevX = currX;
            currX = currX.next;
        }
        
        Node prevY = null, currY = head;
        while(currY != null && currY.value != y){
            prevY = currY;
            currY = currY.next;
        }
        
        if(currX == null || currY == null)
            return;
        
        if(prevX == null)
            head = currY;
        else
            prevX.next = currY;
        
        if(prevY == null)
            head = currX;
        else
            prevY.next = currX;
        
        
        Node temp = currX.next;
        currX.next = currY.next;
        currY.next = temp;
    }
    
}




/*

- given values swap them without swpaing values
- both values are internal values
- adjacent values
- one values could be head

*/
