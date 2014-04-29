#include <stdio.h>
#include <msp_client.h>
// From https://github.com/servalproject/serval-dna/blob/development/doc/Mesh-Streaming-Protocol.md

// Create MSP Socket
int mdp_fd = mdp_socket();
struct msp_sock *sock = msp_socket(mdp_fd);

// Receive inbound events on MSP Socket
// For example, if the file descriptor is identified as having waiting input using poll() or select()
msp_recv(mdp_fd);

/* 
 * After calling msp_recv() you should then call msp_processing() as soon as possible, 
 * so that it can schedule any necessary alarms for asynchronous processing in a timely manner.
 * 
 * This will set next_time to the next time at which msp_processing() should be called. 
 * You should attempt to call msp_processing() again at or before the time indicated.
 * Typically, this might be done with a poll() or select() with an appropriate time out, 
 * so that if no input events occur before next_time, it can be called. 
 * 
 */

time_ms_t next_time;
msp_processing(&next_time);

/*
 * This will set next_time to the next time at which msp_processing() should be called. 
 * You should attempt to call msp_processing() again at or before the time indicated.
 * Typically, this might be done with a poll() or select() with an appropriate time out, 
 *so that if no input events occur before next_time, it can be called. 
 *
 */

/* The socket can be bound to listen on all local SIDs (BIND_ALL), 
 * only the primary SID of the node (BIND_PRIMARY), or to any particular SID passed in via addr.sid.
 */

struct mdp_sockaddr addr;
addr.port = 0;
addr.sid = BIND_ALL;
msp_set_local(msp_sock, addr);
msp_listen(msp_sock);


// Close socket gracefully
msp_shutdown(msp_sock);
