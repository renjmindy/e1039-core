#ifndef PHG4PolyconSteppingAction_h
#define PHG4PolyconSteppingAction_h

#include <g4main/PHG4SteppingAction.h>

#include <string>

class G4VPhysicalVolume;
class PHG4PolyconDetector;
class PHG4Hit;
class PHG4HitContainer;
class PHG4Shower;
class PHParameters;

class PHG4PolyconSteppingAction : public PHG4SteppingAction
{
 public:
  //! constructor
  PHG4PolyconSteppingAction(PHG4PolyconDetector *, const PHParameters *parameters);

  //! destructor
  virtual ~PHG4PolyconSteppingAction();

  //! stepping action
  bool UserSteppingAction(const G4Step *, bool);

  //! reimplemented from base class
  void SetInterfacePointers(PHCompositeNode *);

  void SaveLightYield(const int i = 1) { save_light_yield = i; }
 private:
  //! pointer to the detector
  PHG4PolyconDetector *detector_;

  const PHParameters *params;

  //! pointer to hit container
  PHG4HitContainer *hits_;
  PHG4Hit *hit;
  PHG4Shower *saveshower;
  G4VPhysicalVolume *savevolpre;
  G4VPhysicalVolume *savevolpost;
  int save_light_yield;
  int savetrackid;
  int saveprestepstatus;
  int savepoststepstatus;
  int active;
  int IsBlackHole;
  int use_g4_steps;
  double zmin;
  double zmax;
  double tmin;
  double tmax;
};

#endif
