#ifndef __OPCODE_HPP__
#define __OPCODE_HPP__ 1

enum
{
  //                                                            ------------ STACK ----------
  // Opcode                         operands                    before                  after
  //-----------------------------------------------------------------------------------------------------
  /* 00 */    CALL,             // index, argc                 [rcv, arg...]           [returned]
  /* 01 */    NULL,
  /* 02 */    NULL,
  /* 03 */    NULL,
  /* 04 */    NULL,
  /* 05 */    NULL,
  /* 06 */    NULL,
  /* 07 */    NULL,
  /* 08 */    NULL,
  /* 09 */    NULL,
  /* 10 */    PUSH_NUMBER,      // index                        []                      [ValueObj]

  /* FF */    RETURN            //                              []                      []
};

#endif