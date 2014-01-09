/* -*- c++ -*- */
/* 
 * Copyright 2013 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_HAMMING_WAIT_FOR_PREFIX_BB_IMPL_H
#define INCLUDED_HAMMING_WAIT_FOR_PREFIX_BB_IMPL_H

#include <queue>
#include <hamming/wait_for_prefix_bb.h>

namespace gr {
  namespace hamming {

    class wait_for_prefix_bb_impl : public wait_for_prefix_bb
    {
     private:
      bool _prefix_seen;
      bool _length_seen;
      int _count;
      int _length;
      std::queue<char> _history;
      std::queue<char> _prefix;
      // Nothing to declare in this block.

     public:
      wait_for_prefix_bb_impl();
      ~wait_for_prefix_bb_impl();

      // Where all the action really happens
      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
		       gr_vector_int &ninput_items,
		       gr_vector_const_void_star &input_items,
		       gr_vector_void_star &output_items);
    };

  } // namespace hamming
} // namespace gr

#endif /* INCLUDED_HAMMING_WAIT_FOR_PREFIX_BB_IMPL_H */
