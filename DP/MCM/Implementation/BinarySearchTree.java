public class Main {
   
    // If I had defined Node and BST class as inner class of Main class then I would have to make them static class so that I can access them in main method.
    
    public static void main(String[] args) {
        BST bst = new BST();
        bst.add(20);
        bst.add(4);
        bst.add(100);
        bst.add(10);
        bst.add(5);
        bst.add(2);
        bst.add(7);
        
        System.out.println(bst.find(4));
        bst.delete(4);
        System.out.println(bst.find(4));
        
        System.out.println(bst.find(10));
        bst.delete(10);
        System.out.println(bst.find(10));
        
        System.out.println(bst.find(5));
        bst.delete(5);
        System.out.println(bst.find(5));
        
        System.out.println(bst.find(20));
        bst.delete(20);
        System.out.println(bst.find(20));
        
        bst.inOrderTraversal(bst.root);
        
        
        
    }
}

class Node {
    int value; 
    Node left;
    Node right;
    Node(int value) {
        this.value = value;
        left = null;
        right = null;
    }
};

class BST {
    Node root; 

    BST() { root = null; }

    public void add(int value) {
        root = addRecursively(root, value);
    }

    public boolean find(int value){
        return findRecursively(root, value);
    }

    public boolean findRecursively(Node root, int value) {
        if(root == null)
            return false;
        if(root.value == value)
            return true;
        if(value < root.value)
            return findRecursively(root.left, value);
        else
            return findRecursively(root.right, value);
    }

    public Node addRecursively(Node root, int value) {
        if(root == null)
            return new Node(value);

        if(value < root.value)
            root.left = addRecursively(root.left, value);
        else 
            root.right = addRecursively(root.right, value);

        return root;
    }

    public void delete(int value) {
        root = deleteRecursively(root, value);
    }

    public Node deleteRecursively(Node root, int value) {
        if(root == null)
            return root;

        if(root.value != value){
            if(value < root.value)
                root.left = deleteRecursively(root.left, value);
            else
                root.right = deleteRecursively(root.right, value);
            return root; 
        }

        if(root.left==null && root.right==null)
            return null;
        else if(root.left == null)
            return root.right;
        else if(root.right == null)
            return root.left;

        int smallestValue = findSmallestValueInRightSubTree(root.right);
        root.value = smallestValue;
        root.right = deleteRecursively(root.right, smallestValue);
        return root;
    }

    public int findSmallestValueInRightSubTree(Node root) {
        if(root.left == null)
            return root.value;
        return findSmallestValueInRightSubTree(root.left);
    }

    public void inOrderTraversal(Node root) {
        if(root == null)
            return;
        inOrderTraversal(root.left);
        System.out.println(root.value);
        inOrderTraversal(root.right);
    }
};
    
