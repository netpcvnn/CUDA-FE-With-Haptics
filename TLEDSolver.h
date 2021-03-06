/***************************************************************************/
/*                       CUDA based TLED Solver                            */
/*                     {c} 2008-2010 Karsten Noe                           */
/*                      The Alexandra Institute                            */
/*                   See our blog on cg.alexandra.dk                       */ 
/***************************************************************************/

#include "TetrahedralMesh.h"

namespace TLED {

void precompute(TetrahedralMesh* mesh, TetrahedralTLEDState *state, 
						   float density, float smallestAllowedVolume, float smallestAllowedLength,
   						   float mu, float lambda, float timeStepFactor, float damping); 
void doTimeStep(TetrahedralMesh* mesh, TetrahedralTLEDState *state);
TetrahedralMesh* allocAndCopyMesh(Tetrahedron* hTets, int numTetrahedra, Point* hPoints, int numVertices);
TetrahedralMesh* loadMesh(const char* filename);
void copyStateToHost(TetrahedralTLEDState* state, TetrahedralMesh* mesh, Point* hPoints);
void copyStateToDevice(TetrahedralTLEDState* state, TetrahedralMesh* mesh, Point* hPoints);
void display(unsigned int object_number, TetrahedralMesh* mesh, TetrahedralTLEDState *state, TriangleSurface* surface);
TriangleSurface* loadSurfaceOBJ(const char* filename);
void calculateGravityForces(TetrahedralMesh* mesh, TetrahedralTLEDState *state); 
void applyFloorConstraint(TetrahedralMesh* mesh, TetrahedralTLEDState *state, float floorZPosition); 
void cleanupDisplay(void);
float CPUPrecalculation(TetrahedralMesh *mesh, int blockSize, int& return_maxNumForces, float density, float smallestAllowedVolume, float smallestAllowedLength);
void calculateInternalForces(TetrahedralMesh* mesh, TetrahedralTLEDState *state);

}
