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

#ifndef LANGVM_SE_RUNTIME_VMACH_H_
#define LANGVM_SE_RUNTIME_VMACH_H_

#include "util/list.h"

#include <thread>

class Thread {
 public:

 private:
  std::thread t;
};

struct StackFrame {};

class Stack {
 public:
  void Push(StackFrame sf);
  void Pop();

 private:
  void *stack = nullptr;
};

class VMach {
 public:

  enum : int {
    OK = 0,
    NON_INIT = -1,
  };


/** Initialize Virtual Machine
 * @param file The entry point executable.
 * Each virtual machine must be initialized before starting.
 */
 int Init(FILE *file);

/** Launch Virtual Machine
 * @param m The virtual machine to start.
 * Start a virtual machine.
 * @pre Initialize with Init() before starting.
 */
 int Start();

 private:
  bool init_ = false;
  List<Thread> threads_;
};

#endif //LANGVM_SE_RUNTIME_VMACH_H_
