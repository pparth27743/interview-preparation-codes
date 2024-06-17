// "static void main" must be defined in a public class.
public class Main {
    public static void main(String[] args) {
        
        
        MaxHeap heap = new MaxHeap();
        heap.add(100);
        heap.add(50);
        heap.add(40);
        heap.add(101);
        heap.add(45);
        heap.add(234);
        heap.add(32);
        
        while(!heap.isEmpty()) {
            System.out.print(heap.deleteMax() + " ");
        }
        
        
        
    }
}

class MaxHeap {
    int[] array;
    int totalSize;
    int currentSize;
    
    MaxHeap() {
        currentSize = 0;
        totalSize = 10;
        array = new int[totalSize]; 
    }
    
    private void expandCapacity() {
        totalSize = 2 * totalSize;
        int[] newArray = new int[totalSize];
        for(int i=0; i<currentSize; i++) {
            newArray[i] = array[i];
        }
        array = newArray;
    }
    
    private void swap(int index1, int index2){
        int tempValue = array[index1];
        array[index1] = array[index2];
        array[index2] = tempValue;
    }
    
    public void add(int value) {
        if(currentSize == totalSize){
            expandCapacity();  // TODO
        }
        int index = currentSize;
        array[index] = value;
        currentSize++;
        
        // Heapify Up
        while(index > 0) {
            int parentIndex = (index-1)/2;
            if(array[index] > array[parentIndex]){
                swap(index, parentIndex); // TODO
                index = parentIndex;
            }
            else 
                break;
        }
    }
    
    public int deleteMax() {
        int maxValue = array[0];
        array[0] = array[currentSize-1];
        currentSize--;
        int index = 0;
        //Heapify down
        while(index < currentSize){
            int leftChildIndex = 2*index + 1;
            int rightChildIndex = 2*index + 2;
            int maxValueIndex = index;
            
            if(leftChildIndex < currentSize && array[leftChildIndex] > array[maxValueIndex])
                maxValueIndex = leftChildIndex;
            if(rightChildIndex < currentSize && array[rightChildIndex] > array[maxValueIndex])
                maxValueIndex = rightChildIndex;
            
            if(maxValueIndex != index){
                swap(maxValueIndex, index);
                index = maxValueIndex;
            } else {
                break;
            }
        }
        return maxValue;
    }
    
    public boolean isEmpty() {
        return currentSize == 0;
    }
    
    public int size() {
        return currentSize;
    }
}

      




/*

                     75 
                 50      40           
              30 

add()
deleteMax()
peek()
isEmpty()
size()

*/
