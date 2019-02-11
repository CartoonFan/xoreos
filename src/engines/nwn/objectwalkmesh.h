/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Walkmesh object implementation for NWN.
 */

#ifndef ENGINES_NWN_OBJECTWALKMESH_H
#define ENGINES_NWN_OBJECTWALKMESH_H

#include "glm/vec2.hpp"

#include "src/engines/aurora/objectwalkmesh.h"

namespace Engines {

namespace NWN {

class Placeable;

class ObjectWalkmesh : public Engines::ObjectWalkmesh {
public:
	ObjectWalkmesh(Placeable *placeable);
	~ObjectWalkmesh();

	void load(const Common::UString &resRef,
	          float orientation[4], float position[3]);

	bool in(glm::vec2 &minBox, glm::vec2 &maxBox) const;
	bool in(glm::vec2 &point) const;

	const std::vector<float> &getVertices() const;
	const std::vector<uint32> &getFaces() const;

private:
	void computeMinMax();

	glm::vec2 _min;
	glm::vec2 _max;

	std::vector<float>  _vertices;
	std::vector<uint32> _faces;
};

} // End of namespace NWN

} // End of namespace Engines

#endif // ENGINES_NWN_OBJECTWALKMESH_H