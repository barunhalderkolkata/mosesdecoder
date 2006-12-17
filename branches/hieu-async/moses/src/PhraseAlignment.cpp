// $Id: PhraseAlignment.cpp 988 2006-11-21 19:35:37Z hieuhoang1972 $
/***********************************************************************
Moses - factored phrase-based language decoder
Copyright (C) 2006 University of Edinburgh

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
***********************************************************************/

#include "PhraseAlignment.h"

using namespace std;

AlignInserter PhraseAlignment::GetInserter(FactorDirection direction)
{
	return (direction == Input) ? back_insert_iterator<PhraseAlignVec>(m_sourceAlign)
															: back_insert_iterator<PhraseAlignVec>(m_targetAlign);
}

TO_STRING_BODY(PhraseAlignment);

void OutputPhraseAlignVec(std::ostream &out, const PhraseAlignVec &phraseAlignVec)
{
	
	for (size_t pos = 0 ; pos < phraseAlignVec.size() ; ++pos)
	{
		const AlignVec &alignVec = phraseAlignVec[pos];
		if (alignVec.size() > 0)
		{
			out << "[" << alignVec[0];
			for (size_t index = 1 ; index < alignVec.size() ; ++index)
			{
				out << "," << alignVec[index];
			}
			out << "] ";
		}
	}
	
}

std::ostream& operator<<(std::ostream &out, const PhraseAlignment &phraseAlignment)
{
	OutputPhraseAlignVec(out, phraseAlignment.m_sourceAlign);
	out << " to ";
	OutputPhraseAlignVec(out, phraseAlignment.m_targetAlign);
	return out;
}