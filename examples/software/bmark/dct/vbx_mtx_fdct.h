/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2016 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of VectorBlox Computing Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This agreement shall be governed in all respects by the laws of the Province
 * of British Columbia and by the laws of Canada.
 *
 * This file is part of the VectorBlox MXP Software Development Kit.
 *
 */


#ifndef __VBX_MTX_FDCT_H_
#define __VBX_MTX_FDCT_H_

typedef struct {

	int db; // double-buffer flag

	// primary results
	vbx_half_t *vimage[2];	// DMA, VPU
	vbx_half_t *vblock[3];  // DMA, TMP, VPU
	vbx_half_t *vcoeff;

	// other intermediate calcs
	vbx_half_t *vprods;
	vbx_half_t *vaccum;
	vbx_half_t *vflags;

} vbx_mtx_fdct_t;


//void vbx_mtx_fdct_init(void);

void vbx_mtx_fdct_scalar( dt *block_s, dt *coeff_s, dt *image, int start_x, int start_y, int num_tile_x, int num_tile_y );

vbx_mtx_fdct_t *
     vbx_mtx_fdct_init( dt *coeff_v, dt *image );

void vbx_mtx_fdct_free( vbx_mtx_fdct_t *v );

void vbx_mtx_fdct( vbx_mtx_fdct_t *v, dt *block_v, dt *image,
                   int start_x, int start_y, int end_x, int end_y, int num_tile_x, int num_tile_y );

#endif // __VBX_MTX_FDCT_H_
