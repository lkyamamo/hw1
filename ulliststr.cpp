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

bool ULListStr::empty() const
{
  if ((tail_ == head_) && (tail_ -> last == tail_ -> first))
  {
    return true;
  }
  else
  {
    return false;
  }
  
}

void ULListStr::push_back(const std::string& val)
{
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
}

void ULListStr::pop_back()
{
  (tail_ -> last)--;

  //deallocate if empty
  if(tail_ -> last == tail_ -> first)
  {
    tail_ = tail_ -> prev;
    delete (tail_ -> next);
  }
}

void ULListStr::push_front(const std::string& val)
{
  
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
