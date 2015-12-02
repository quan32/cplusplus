#ifndef parameter_h
#define parameter_h
enum PARAM {
    INCREMENT = 1,
    DECREMENT = -1,
};

enum ALERT_STATE {
    UNKNOWN                 = 1,
    
    ERROR_INVALID_INDEX     = 10,
    ERROR_MEMORY_MALLOC     = 11,
    
    
    INFOR_EMPTY_ARRAY       = 20,
    INFOR_FOUNDED           = 21,
    INFOR_UNFOUNDED         = 22,
};
#endif
