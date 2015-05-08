/**
 * @file
 * @ingroup smGroup
 * Declaration of the auxiliary interface for a FW State Machine.
 * The auxiliary interface offers functions which support the
 * development of an application which uses the FW State Machine
 * but which are not expected to be used during normal operation.
 * @author Vaclav Cechticky <vaclav.cechticky@pnp-software.com>
 * @author Alessandro Pasetti <pasetti@pnp-software.com>
 * @copyright P&P Software GmbH, 2011, All Rights Reserved
 *
 * This file is part of FW Profile.
 *
 * FW Profile is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FW Profile is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with FW Profile.  If not, see <http://www.gnu.org/licenses/>.
 *
 * For information on alternative licensing, please contact P&P Software GmbH.
 */

#ifndef FWSM_AUX_H_
#define FWSM_AUX_H_

#include <stdio.h>
#include "FwSmCore.h"

/**
 * Print the configuration of the state machine to an output stream.
 * This function extracts all the configuration information from the
 * argument state machine and prints it to the argument output stream.
 * It is legal for the argument state machine to be only partly configured.
 * It is also legal to call this function on a state machine which has
 * already been started.
 * 
 * The function describes the configuration of the argument state machine
 * in terms of its states, choice pseudo-states, transitions, actions
 * and guards.
 * The following conventions are used to refer to these items:
 * - The name of a state is its identifier.
 * - The name of a choice pseudo-state is its identifier.
 * - Transitions are identified by their source, destination,
 *   transition identifier, transition action and guard.
 * - The name of an action is an integer in the range [1,N] where N is
 *   total number of actions declared for the state machine and the
 *   action with identifier 'i' is the i-th action to have been added
 *   to the state machine.
 * - The name of a guard is an integer in the range [1,M] where M is
 *   total number of guards declared for the state machine and the
 *   guard with identifier 'i' is the i-th guard to have been added
 *   to the state machine.
 * 
 * This function assumes the argument output stream to be open and
 * to have enough space to receive the output generated by the function.
 * The function neither closes nor flushes the output stream.
 * Opening and closing of the output stream must thus be done by the caller.
 * @param smDesc the descriptor of the state machine to be started.
 * @param stream the output stream to which the configuration information is
 * printed.
 */
void FwSmPrintConfig(FwSmDesc_t smDesc, FILE *stream);

/**
 * Print the configuration of the state machine and its embedded state machines
 * to an output stream.
 * This is a recursive version of <code>::FwSmPrintConfig</code> which operates
 * on a state machine and, recursively, on all its embedded state machines.
 * This function assumes the argument output stream to be open and
 * to have enough space to receive the output generated by the function.
 * The function neither closes nor flushes the output stream.
 * Opening and closing of the output stream must thus be done by the caller.
 * @param smDesc the descriptor of the state machine to be started.
 * @param stream the output stream to which the configuration information is
 * printed.
 */
void FwSmPrintConfigRec(FwSmDesc_t smDesc, FILE *stream);

/**
 * Print the name of a state machine error code.
 * Error code are defined as instances of an enumerated type in
 * <code>FwSmConstants.h</code>.
 * This function translates an error code to a string holding the
 * name of its enumerated value.
 * @param errCode the error code
 * @return the string holding the name of the error code
 */
char* FwSmPrintErrCode(FwSmErrCode_t errCode);

#endif /* FWSM_AUX_H_ */
