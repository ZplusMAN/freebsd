/*-
 * Copyright (C) 2012 Intel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

__FBSDID("$FreeBSD$");

#ifndef __IOAT_HW_H__
#define __IOAT_HW_H__

#define	IOAT_MAX_CHANNELS		32

#define	IOAT_CHANCNT_OFFSET		0x00

#define	IOAT_XFERCAP_OFFSET		0x01
/* Only bits [4:0] are valid. */
#define	IOAT_XFERCAP_VALID_MASK		0x1f

#define	IOAT_GENCTRL_OFFSET		0x02

#define	IOAT_INTRCTRL_OFFSET		0x03
#define	IOAT_INTRCTRL_MASTER_INT_EN	0x01

#define	IOAT_ATTNSTATUS_OFFSET		0x04

#define	IOAT_CBVER_OFFSET		0x08

#define	IOAT_VER_3_0			0x30
#define	IOAT_VER_3_3			0x33

#define	IOAT_INTRDELAY_OFFSET		0x0C

#define	IOAT_CS_STATUS_OFFSET		0x0E

#define	IOAT_DMACAPABILITY_OFFSET	0x10

/* DMA Channel Registers */
#define	IOAT_CHANCTRL_OFFSET			0x80
#define	IOAT_CHANCTRL_CHANNEL_PRIORITY_MASK	0xF000
#define	IOAT_CHANCTRL_COMPL_DCA_EN		0x0200
#define	IOAT_CHANCTRL_CHANNEL_IN_USE		0x0100
#define	IOAT_CHANCTRL_DESCRIPTOR_ADDR_SNOOP_CONTROL	0x0020
#define	IOAT_CHANCTRL_ERR_INT_EN		0x0010
#define	IOAT_CHANCTRL_ANY_ERR_ABORT_EN		0x0008
#define	IOAT_CHANCTRL_ERR_COMPLETION_EN		0x0004
#define	IOAT_CHANCTRL_INT_REARM			0x0001
#define	IOAT_CHANCTRL_RUN			(IOAT_CHANCTRL_INT_REARM |\
						 IOAT_CHANCTRL_ANY_ERR_ABORT_EN)

#define	IOAT_CHANCMD_OFFSET		0x84
#define	IOAT_CHANCMD_RESET		0x20
#define	IOAT_CHANCMD_SUSPEND		0x04

#define	IOAT_DMACOUNT_OFFSET		0x86

#define	IOAT_CHANSTS_OFFSET_LOW		0x88
#define	IOAT_CHANSTS_OFFSET_HIGH	0x8C
#define	IOAT_CHANSTS_OFFSET		0x88

#define	IOAT_CHANSTS_STATUS		0x7ULL
#define	IOAT_CHANSTS_ACTIVE		0x0
#define	IOAT_CHANSTS_IDLE		0x1
#define	IOAT_CHANSTS_SUSPENDED		0x2
#define	IOAT_CHANSTS_HALTED		0x3

#define	IOAT_CHANSTS_UNAFFILIATED_ERROR	0x8ULL
#define	IOAT_CHANSTS_SOFT_ERROR		0x10ULL

#define	IOAT_CHANSTS_COMPLETED_DESCRIPTOR_MASK	(~0x3FULL)

#define	IOAT_CHAINADDR_OFFSET_LOW	0x90
#define	IOAT_CHAINADDR_OFFSET_HIGH	0x94

#define	IOAT_CHANCMP_OFFSET_LOW		0x98
#define	IOAT_CHANCMP_OFFSET_HIGH	0x9C

#define	IOAT_CHANERR_OFFSET		0xA8

#define	IOAT_CHANERR_XSADDERR		(1 << 0)
#define	IOAT_CHANERR_XDADDERR		(1 << 1)
#define	IOAT_CHANERR_NDADDERR		(1 << 2)
#define	IOAT_CHANERR_DERR		(1 << 3)
#define	IOAT_CHANERR_CHADDERR		(1 << 4)
#define	IOAT_CHANERR_CCMDERR		(1 << 5)
#define	IOAT_CHANERR_CUNCORERR		(1 << 6)
#define	IOAT_CHANERR_DUNCORERR		(1 << 7)
#define	IOAT_CHANERR_RDERR		(1 << 8)
#define	IOAT_CHANERR_WDERR		(1 << 9)
#define	IOAT_CHANERR_DCERR		(1 << 10)
#define	IOAT_CHANERR_DXSERR		(1 << 11)
#define	IOAT_CHANERR_CMPADDERR		(1 << 12)
#define	IOAT_CHANERR_INTCFGERR		(1 << 13)
#define	IOAT_CHANERR_SEDERR		(1 << 14)
#define	IOAT_CHANERR_UNAFFERR		(1 << 15)
#define	IOAT_CHANERR_CXPERR		(1 << 16)
/* Reserved.				(1 << 17) */
#define	IOAT_CHANERR_DCNTERR		(1 << 18)
#define	IOAT_CHANERR_DIFFERR		(1 << 19)
#define	IOAT_CHANERR_GTVERR		(1 << 20)
#define	IOAT_CHANERR_ATVERR		(1 << 21)
#define	IOAT_CHANERR_RTVERR		(1 << 22)
#define	IOAT_CHANERR_BBERR		(1 << 23)
#define	IOAT_CHANERR_RDIFFERR		(1 << 24)
#define	IOAT_CHANERR_RGTVERR		(1 << 25)
#define	IOAT_CHANERR_RATVERR		(1 << 26)
#define	IOAT_CHANERR_RRTVERR		(1 << 27)

#define	IOAT_CHANERR_STR \
    "\20\34RRTVERR\33RATVERR\32RGTVERR\31RDIFFERR\30BBERR\27RTVERR\26ATVERR" \
    "\25GTVERR\24DIFFERR\23DCNTERR\21CXPERR\20UNAFFERR\17SEDERR\16INTCFGERR" \
    "\15CMPADDERR\14DXSERR\13DCERR\12WDERR\11RDERR\10DUNCORERR\07CUNCORERR" \
    "\06CCMDERR\05CHADDERR\04DERR\03NDADDERR\02XDADDERR\01XSADDERR"


#define	IOAT_CFG_CHANERR_INT_OFFSET		0x180
#define	IOAT_CFG_CHANERRMASK_INT_OFFSET		0x184

#define	IOAT_MIN_ORDER			4
#define	IOAT_MAX_ORDER			16

#endif /* __IOAT_HW_H__ */
