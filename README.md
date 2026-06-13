# EmbedKit_HimanshuPawar
Embedded C Utility Library Assignment


## Name
Himanshu Pawar

## Project Title
Circular Buffer Implementation in C

## Description
This project implements a fixed-size circular buffer (ring buffer) for `uint8_t` data with a capacity of 8 bytes.

The implementation supports:
- Buffer initialization
- Write operation
- Read operation
- Empty check
- Full check
- Count query
- Overflow protection
- Wrap-around functionality

The buffer never overwrites unread data when full and never returns invalid data when empty.

---

## Features

- Initialize buffer to an empty state
- Write one byte into the buffer
- Read one byte from the buffer
- Check if buffer is empty
- Check if buffer is full
- Query current number of stored bytes
- Prevent buffer overflow
- Prevent reading from an empty buffer
- Support circular wrap-around

---

## Buffer Specifications

| Parameter | Value |
|-----------|-------|
| Data Type | uint8_t |
| Capacity | 8 Bytes |
| Read Policy | FIFO (First In First Out) |
| Overflow Handling | Write Fails |
| Empty Read Handling | Read Fails |

---

## Implemented APIs

### ringbuf_init()
Initializes the ring buffer and sets head, tail, and count to zero.

### ringbuf_write()
Writes one byte into the buffer.

Returns:
- 0 on success
- -1 if buffer is full

### ringbuf_read()
Reads one byte from the buffer.

Returns:
- 0 on success
- -1 if buffer is empty

### ringbuf_is_empty()
Checks whether the buffer is empty.

Returns:
- 1 if empty
- 0 otherwise

### ringbuf_is_full()
Checks whether the buffer is full.

Returns:
- 1 if full
- 0 otherwise

### ringbuf_count()
Returns the current number of bytes stored in the buffer.

---

## Test Sequence Implemented

### Step 1
Write 8 bytes:

`0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48`

Verify:
- Buffer becomes full
- Count equals 8

### Step 2
Attempt to write:

`0x99`

Expected:
- Write fails
- Buffer full message displayed

### Step 3
Read 3 bytes.

Expected output:

`0x41, 0x42, 0x43`

Verify:
- Count becomes 5

### Step 4
Write:

`0x49, 0x4A, 0x4B`

Verify:
- Freed slots are reused
- Count becomes 8

### Step 5
Read all remaining bytes.

Expected output:

`0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B`

Verify:
- Buffer becomes empty

### Step 6
Attempt to read from empty buffer.

Expected:
- Read fails
- Buffer empty message displayed

---

## Build Instructions


### Compile 
gcc -Wall -std=c99 ringbuf.c -o ringbuf
<img width="1013" height="326" alt="image" src="https://github.com/user-attachments/assets/4e1c4a59-9ba4-4914-92fb-942e1245b776" />


### OUTPUT 

<img width="471" height="610" alt="image" src="https://github.com/user-attachments/assets/9bb80a05-2fc4-4fbf-8358-c19cea5c017c" />




