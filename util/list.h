/*
   Copyright 2011 LangVM Authors

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef LANGVM_UTIL_LIST_H_
#define LANGVM_UTIL_LIST_H_

#include <mutex>

template <typename T>
class List {
 private:

  struct Node {
    T e;
    Node *next;
  };

  unsigned int length_ = 0; // Synchronized

  std::mutex mutex_;
  Node list_head_;
  Node *current; // Synchronized

 public:

  List();
  ~List();

  /** Add to list end (synchronized)
   * @param element Save the element
   */
  void Append(T element);

  /** Delete next node from list (synchronized)
   * @param node Previous node of the target node.
   */
  void DeleteNext(Node *node);

  /** Get length (synchronized) */
  inline unsigned int GetLength() {
    unsigned int length;
    mutex_.lock();

    length = length_;

    mutex_.unlock();
    return length;
  }
};

#endif //LANGVM_UTIL_LIST_H_
