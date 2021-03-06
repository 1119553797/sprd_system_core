/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _DEBUGGERD_TOMBSTONE_H
#define _DEBUGGERD_TOMBSTONE_H

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

#include <corkscrew/ptrace.h>

int check_corefile_limit(void);

/* Creates a tombstone file and writes the crash dump to it.
 * Returns the path of the tombstone, which must be freed using free(). */
char* engrave_tombstone(pid_t pid, pid_t tid, int signal, uintptr_t abort_msg_address,
        bool dump_sibling_threads, bool quiet, bool* detach_failed, int* total_sleep_time_usec);

#endif // _DEBUGGERD_TOMBSTONE_H
