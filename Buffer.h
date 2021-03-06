//
// Created by mano on 10.12.16.
//

#ifndef PORTFORWARDERREDEAWROFTROP_BUFFER_H
#define PORTFORWARDERREDEAWROFTROP_BUFFER_H

#include "Includes.h"

class Buffer {
    char * buf;

    size_t end;
    size_t size;

    bool flag_correct_buffer;

    bool flag_finished;
    bool flag_finished_correct;

public:
    Buffer(size_t size);

    Buffer();

    bool is_have_data(size_t offs) { return end > offs; }

    bool is_finished() { return flag_finished;}

    bool is_finished_correct() { return flag_finished && flag_finished_correct; }

    void set_finished_correct() { flag_finished = true;  flag_finished_correct = true; }

    void set_finished_incorrect() { flag_finished = true; flag_finished_correct = false;}

    size_t get_data_size(size_t offs) { return end - offs; }

    size_t get_empty_space_size() { return size - end; }

    size_t get_capacity() { return size; }

    char * get_buf_offs(size_t offs) { return buf + offs; }

    char * get_end() { return buf + end; }

    int do_resize(size_t new_size);

    int do_move_end(ssize_t received);

    void add_data_to_end(const char * from, size_t size_data);

    void add_symbol_to_end(char c);

    ~Buffer();
};


#endif //PORTFORWARDERREDEAWROFTROP_BUFFER_H
