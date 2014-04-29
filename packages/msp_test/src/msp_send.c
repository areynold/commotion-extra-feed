#include <stdio.h>
#include <msp_client.h>

int msp_send(struct msp_sock *sock, const uint8_t *payload, size_t len);

/* Data is not actually sent until the next call to msp_processing(), 
 * which should be triggered as soon as possible. Message boundaries 
 * are preserved from end to end. Zero length messages are not currently supported.
 * 
 * In the event that there is insufficient buffer space to send the message, 
 * msp_send() will return -1. If this occurs, you should wait until the next time 
 * your handler function is called with the MSP_STATE_DATAOUT flag set in the state argument.
 * int msp_send(struct msp_sock *sock, const uint8_t *payload, size_t len);
 */

msp_set_handler(sock, handler_function, context);

int handler_function(struct msp_sock *sock, msp_state_t state, const uint8_t *payload, size_t len, void *context){

if (state & MSP_STATE_ERROR){
    // something went wrong, eg connection timeout or an unspecified error was returned from serval's daemon.
  }

  if (payload && len){
    // process incoming message bytes and return 0
    // all incoming messages will be delivered in the same order they were sent

    // if you can't process the whole message now, return 1
    // later when you believe you will be able to process this message, call msp_processing again
  }

  if (state & MSP_STATE_DATA_OUT){
    // a call to msp_send() should now succeed.
  }

  if (state & MSP_STATE_SHUTDOWN_REMOTE){
    // the remote party has stopped sending data and would like to close.
    // you may keep your end of the connection open and continue to send data. 
    // When both ends have shutdown the connection will be closed.
  }

  if (state & MSP_STATE_CLOSED){
    // No matter how the socket it closed, this function should always be called exactly once with a closed state before the struct msp_sock* is free'd
    // Any other resources associated with the socket should now be released.
  }

  // if you return -1, the socket will be flagged a closed
}

msp_shutdown(sock)
