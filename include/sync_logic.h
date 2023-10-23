#ifndef SYNC_LOGIC_H
#define SYNC_LOGIC_H

// Function prototype for local two-way synchronization
void local_two_way_sync(const char *dir1, const char *dir2);

// Function prototypes for remote synchronization
void remote_sync_server(int port);
void remote_sync_client(const char *ip_address, int port);

// Function for the actual sync logic
void two_way_sync_logic(const char *dir1, const char *dir2);

#endif // SYNC_LOGIC_H
