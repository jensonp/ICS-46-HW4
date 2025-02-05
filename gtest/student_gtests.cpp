#include <gtest/gtest.h>
#include "../src/Timer.h"
#include "../src/holder.h"
#include "../src/is_balanced.h"

TEST(AS_Test, push_pop_top_is_empty) {
    ArrayStack stack(10);

    EXPECT_TRUE(stack.is_empty());
    stack.push("apple"); EXPECT_FALSE(stack.is_empty()); EXPECT_EQ(stack.top(), "apple");
    stack.push("beer"); EXPECT_EQ(stack.top(), "beer");
    stack.pop(); EXPECT_EQ(stack.top(), "apple");
    stack.pop(); EXPECT_TRUE(stack.is_empty());
}
TEST(LS_Test, push_pop_top_is_empty) {
    LinkedStack stack; 
    
    EXPECT_TRUE(stack.is_empty());
    stack.push("apple"); EXPECT_FALSE(stack.is_empty()); EXPECT_EQ(stack.top(), "apple");
    stack.push("beer"); EXPECT_EQ(stack.top(), "beer");
    stack.pop(); EXPECT_EQ(stack.top(), "apple");
    stack.pop(); EXPECT_TRUE(stack.is_empty());
}

TEST(AQ_Test, enq_deq_next_is_empty) {
    ArrayQueue queue(10);

    EXPECT_TRUE(queue.is_empty());
    queue.enq("mope"); EXPECT_FALSE(queue.is_empty()); EXPECT_EQ(queue.next(), "mope");
    queue.enq("soap"); EXPECT_EQ(queue.next(), "mope");
    queue.deq(); EXPECT_EQ(queue.next(), "soap");
    queue.deq(); EXPECT_TRUE(queue.is_empty());
}

TEST(LQ_Test, enq_deq_next_is_empty) {
    LinkedQueue queue;
    EXPECT_TRUE(queue.is_empty());
    queue.enq("mope"); EXPECT_FALSE(queue.is_empty()); EXPECT_EQ(queue.next(), "mope");
    queue.enq("soap"); EXPECT_EQ(queue.next(), "mope");
    queue.deq(); EXPECT_EQ(queue.next(), "soap");
    queue.deq(); EXPECT_TRUE(queue.is_empty());
}

TEST(balanced_test, parenthesis) {
    std::string balanced = "<>([{()}])(<>)";
    EXPECT_TRUE(is_balanced(balanced));
    std::string unbalanced = "(((([({})])))";
    EXPECT_FALSE(is_balanced(unbalanced));
}