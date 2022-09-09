#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

//ready to check

void ULListStr::push_back(const std::string& val)
{
  //no items
  if(empty())
  {
    head_ = new Item;
    tail_ = head_;
  }

  //will this go off the end -> create new item
  if(tail_ -> last == ARRSIZE)
  {
    tail_ -> next = new Item;
    tail_ -> next -> prev = tail_;
    tail_ = tail_ -> next;
  }

  //add value to end of current array
  tail_ -> val[tail_ -> last] = val;
  (tail_->last)++;
  ++size_;
}

void ULListStr::pop_back()
{
  //look here first if any memory leaks
  (tail_ -> last)--;
  --size_;

  //deallocate if empty
  if(tail_ -> last == tail_ -> first)
  {
    tail_ = tail_ -> prev;
    delete (tail_ -> next);
    tail_ -> next = NULL;
  }
}

void ULListStr::push_front(const std::string& val)
{
  //no items
  if(empty())
  {
    head_ = new Item;
    tail_ = head_;
  }

  //see if can add to front
  if(head_ -> first == 0)
  {
    head_ -> prev = new Item;
    head_ -> prev -> next = head_;
    head_ = head_ -> prev;
    //setting first to end of array
    head_ -> first = 10;
    head_ -> last = 10;
  }

  //add value before first element of array
  head_ -> val[head_ -> first - 1] = val;
  (head_ -> first)--;
  ++size_;
}

void ULListStr::pop_front()
{
  //look here first for any memory leaks
  (head_ -> first)++;
  --size_;

  if(head_ -> first == head_ -> last)
  {
    head_ = head_ -> next;
    delete (head_ -> prev);
    head_ -> prev = NULL;
  }
}

//look here if compiler errors
std::string const & ULListStr::back() const
{
  return (tail_ -> val[(tail_ -> last) - 1]);
}

std::string const & ULListStr::front() const
{
  return (head_ -> val[head_ -> first]);
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* temp = head_;
  while((loc >= (temp -> last) - (temp -> first)) && (temp -> next) != NULL)
  {
    loc -= (temp -> last) - (temp -> first);
    temp = temp -> next;
  }
  //incase loc going over
  if (loc >= ((temp -> last) - (temp -> first)))
  {
    return NULL;
  }
  
  //check math here for the - 1 term if not returning correct value
  return &(temp -> val[(temp -> first) + loc]);

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
