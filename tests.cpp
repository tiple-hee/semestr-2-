#include <gtest/gtest.h>
#include "PriorityQueue.h"

TEST(PriorityQueueTest, DefaultConstructor)
{
    PriorityQueue pq;
    EXPECT_EQ(pq.get_size(), 0);
    EXPECT_TRUE(pq.is_empty());
    EXPECT_EQ(pq.to_string(), "Empty");
}

TEST(PriorityQueueTest, InitializerListAndSort)
{
    PriorityQueue pq = {5, 15, 25};
    EXPECT_EQ(pq.get_size(), 3);
    EXPECT_EQ(pq.getMax(), 25);
    EXPECT_EQ(pq.to_string(), "25 15 5");
}

TEST(PriorityQueueTest, CopyLogic)
{
    PriorityQueue pq1 = {1, 2, 3};
    PriorityQueue pq2 = pq1;
    EXPECT_EQ(pq2.to_string(), pq1.to_string());

    pq2.removeMax(); 
    EXPECT_NE(pq2.getMax(), pq1.getMax()); 
}

TEST(PriorityQueueTest, AssignmentOperator)
{
    PriorityQueue pq1 = {7, 8, 9};
    PriorityQueue pq2;
    pq2 = pq1;
    EXPECT_EQ(pq2.to_string(), "9 8 7");
}

TEST(PriorityQueueTest, InsertElement)
{
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(30);
    pq.insert(20);
    EXPECT_EQ(pq.to_string(), "30 20 10");
}

TEST(PriorityQueueTest, RemoveMaxElement)
{
    PriorityQueue pq = {10, 20, 30};
    pq.removeMax();
    EXPECT_EQ(pq.to_string(), "20 10");
    EXPECT_EQ(pq.get_size(), 2);
}

TEST(PriorityQueueTest, OutOfRangeErrors)
{
    PriorityQueue pq;
    EXPECT_THROW(pq.getMax(), std::out_of_range);
    EXPECT_THROW(pq.removeMax(), std::out_of_range);
}
