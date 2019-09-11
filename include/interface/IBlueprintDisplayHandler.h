#ifndef IBLUEPRINTDISPLAYHANDLER_H
#define IBLUEPRINTDISPLAYHANDLER_H
#include <string>

/*
 * The interface which request GUI to load certain blueprint.
 */
class IBlueprintDisplayHandler {
public:
  virtual void loadBlueprint(std::string name) = 0;
};

#endif /* IBLUEPRINTDISPLAYHANDLER_H */