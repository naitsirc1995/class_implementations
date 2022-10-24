package br.impa.algorithms.FibImplementation;

import java.util.*;

import javax.naming.spi.DirStateFactory.Result;


public final class FibHeap<T> {

    public static final class Entry<T> {
        private int mDegree = 0; // Number of children
        private boolean mIsMarked = false; // Whether this node is marked

        private Entry<T> mNext;
        private Entry<T> mPrev;

        private Entry<T> mParent;
        private Entry<T> mChild;

        private T mElem;
        private double mPriority;

        public T getValue(){
            return mElem;
        }

        public void setValue(T value){
            mElem = value;
        }

        public double getPriority(){
            return mPriority;
        }

        private Entry(T elem, double priority){
            mNext = mPrev = this;
            mElem = elem;
            mPriority = priority;
        }
    }


    private Entry<T> mMin = null; // Here we keep reference of the min element
    private int mSize = 0;


    public Entry<T> enqueue(T value, double priority){
        checkPriority(priority);

        Entry<T> result = new Entry<T>(value,priority);

        mMin = mergeLists(mMin, result);

        ++mSize;

        return result;
    }

    public Entry<T> min() {
        if (isEmpty())
            throw new NoSuchElementException("Heap is empty");
        return mMin;
    }

    public boolean isEmpty() {
        return mMin == null;
    }

    public int size(){
        return mSize;
    }

    public static <T> FibHeap<T> merge(FibHeap<T> one, FibHeap<T> two){
        FibHeap<T> result = new FibHeap<T>();
        result.mMin = mergeLists(one.mMin, two.mMin);

        result.mSize = one.mSize + two.mSize;
        one.mSize = two.mSize = 0;
        one.mMin = null;
        two.mMin = null;
        return result;
    }

    public Entry<T> dequeueMin(){
        if (isEmpty())
            throw new NoSuchElementException("Heap is empty.");
        --mSize;

        Entry<T> minElem = mMin;

        if (mMin.mNext == mMin){
            mMin = null;            
        } else {
            mMin.mPrev.mNext = mMin.mNext;
            mMin.mNext.mPrev = mMin.mPrev;
            mMin = mMin.mNext; // Arbitrary element from the root list. 
        }

        if (minElem.mChild != null){
            Entry<?> curr = minElem.mChild;
            do {
                curr.mElem = null;
                curr = curr.mNext;
            } while (curr != minElem.mChild);
        }

        // There are a lot of things I still have to understand from here. 
        // So, let's continue later at some point during the day
        
        mMin = mergeLists(mMin, minElem.mChild);

        return minElem;
    }

    private static<T> Entry<T> mergeLists(Entry<T> one, Entry<T> two){

        if (one == null && two == null){
            return null;
        }

        else if (one != null && two == null){
            return one;
        }

        else if (one == null && two != null){
            return two;
        } else {
            Entry<T> oneNext = one.mNext;
            one.mNext.mPrev = two;
            two.mNext = oneNext;
            two.mNext.mPrev = two;            
            return one.mPriority < two.mPriority ? one : two;
        }
    }

    public void checkPriority(double priority){
        if (Double.isNaN(priority))
            throw new IllegalArgumentException(priority + " is invalid");
    }
}