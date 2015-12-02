#include "array.h"

/***
 * ArrayData
 *
 */
ArrayData::ArrayData(int val, int pos) {
    value       =val;
    position    = pos;
    next        = NULL;
}


/***
 * Alert class's implementation
 *
 */
Alert::Alert() {
    state   = UNKNOWN;
    message = "";
}
void Alert::set(ALERT_STATE alert_state, const string alert_message) {
    state   = alert_state;
    message = alert_message;
}
bool Alert::isFounded() {
    return (state == INFOR_FOUNDED);
}
ALERT_STATE Alert::getState() {
    return state;
}
void Alert::alert() {
    switch (state) {
        case ERROR_INVALID_INDEX:
            cout << "INVALID_INDEX:" << message << endl;
            exit(-1);
            
        case ERROR_MEMORY_MALLOC:
            cout << "No more memory available" << endl;
            exit(-1);
            
        case INFOR_EMPTY_ARRAY:
            cout << "Empty Array" << endl;
            break;
            
        default:
            break;
    }
}