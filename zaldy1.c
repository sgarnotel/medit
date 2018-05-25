/****************************************************************************/
/* This file is part of FreeFem++.                                          */
/*                                                                          */
/* FreeFem++ is free software: you can redistribute it and/or modify        */
/* it under the terms of the GNU Lesser General Public License as           */
/* published by the Free Software Foundation, either version 3 of           */
/* the License, or (at your option) any later version.                      */
/*                                                                          */
/* FreeFem++ is distributed in the hope that it will be useful,             */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            */
/* GNU Lesser General Public License for more details.                      */
/*                                                                          */
/* You should have received a copy of the GNU Lesser General Public License */
/* along with FreeFem++. If not, see <http://www.gnu.org/licenses/>.        */
/****************************************************************************/
/* SUMMARY : Memory allocation for data structures
 * LICENSE : LGPLv3
 * ORG     : LJLL Universite Pierre et Marie Curie, Paris, FRANCE
 * AUTHORS : Pascal Frey
 *           Simon Garnotel
 * E-MAIL  : pascal.frey@sorbonne-universite.fr
 *           simon.garnotel@gmail.com
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>
#include <stdlib.h>
#include "medit.h"
#include "extern.h"
#include "sproto.h"

/*!
 * Allocation function
 *
 * Allocate points, triangles, quadrangles, tetrahedra, hexahedral, edges and extra
 */
int zaldy1 (pMesh mesh) {
	if (ddebug) printf("allocate %d points\n", mesh->np);
	mesh->point = (pPoint)M_calloc(mesh->np + 1, sizeof(Point), "zaldy1.point");
	if (!mesh->point) {
		if (ddebug) printf("allocation failed");
		return (0);
	}
	// assert(mesh->point);

	if (ddebug) printf("allocate %d tria\n", mesh->nt);
	mesh->tria = (pTriangle)M_calloc(mesh->nt + 1, sizeof(Triangle), "zaldy1.tria");
	if (!mesh->tria) {
		if (ddebug) printf("allocation failed");
		return (0);
	}
	// assert(mesh->tria);

	if (mesh->nq) {
		if (ddebug) printf("allocate %d quad\n", mesh->nq);
		mesh->quad = (pQuad)M_calloc(mesh->nq + 1, sizeof(Quad), "zaldy1.quad");
		if (!mesh->quad) {
			if (ddebug) printf("allocation failed");
			return (0);
		}
		// assert(mesh->quad);
	}

	if (mesh->ntet) {
		if (ddebug) printf("allocate %d tetra\n", mesh->ntet);
		mesh->tetra = (pTetra)M_calloc(mesh->ntet + 1, sizeof(Tetra), "zaldy1.tetra");
		if (!mesh->tetra) {
			if (ddebug) printf("allocation failed");
			return (0);
		}
		// assert(mesh->tetra);
	}

	if (mesh->nhex) {
		if (ddebug) printf("allocate %d hexa\n", mesh->nhex);
		mesh->hexa = (pHexa)M_calloc(mesh->nhex + 1, sizeof(Hexa), "zaldy1.hexa");
		if (!mesh->hexa) {
			if (ddebug) printf("allocation failed");
			return (0);
		}
		// assert(mesh->hexa);
	}

	if (mesh->na) {
		if (ddebug) printf("allocate %d edges\n", mesh->na);
		mesh->edge = (pEdge)M_calloc(mesh->na + 1, sizeof(Edge), "zaldy1.edge");
		if (!mesh->edge) {
			if (ddebug) printf("allocation failed");
			return (0);
		}
		// assert(mesh->edge);
	}

	if (mesh->nvn || mesh->ntg) {
		if (ddebug) printf("allocate extra\n");
		mesh->extra = (pExtra)M_calloc(1, sizeof(Extra), "zaldy1.extra");
		if (!mesh->extra) {
			if (ddebug) printf("allocation failed");
			return (0);
		}
		// assert(mesh->extra);

		if (mesh->nvn) {
			if (ddebug) printf("allocate inmesh (extra/n)\n");
			mesh->extra->n = (float *)M_calloc(3 * mesh->nvn + 1, sizeof(float), "inmesh");
			if (!mesh->extra->n) {
				if (ddebug) printf("allocation failed");
				return (0);
			}
			// assert(mesh->extra->n);
		}

		if (mesh->ntg) {
			if (ddebug) printf("allocate inmesh (extra/t)\n");
			mesh->extra->t = (float *)M_calloc(3 * mesh->ntg + 1, sizeof(float), "inmesh");
			if (!mesh->extra->t) {
				if (ddebug) printf("allocation failed");
				return (0);
			}
			// assert(mesh->extra->n);
		}
	}

	return (1);
}
