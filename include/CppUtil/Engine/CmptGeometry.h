#ifndef _ENGINE_COMPONENT_CMPT_GEOMETRY_H_
#define _ENGINE_COMPONENT_CMPT_GEOMETRY_H_

#include <CppUtil/Engine/Component.h>

namespace CppUtil {
	namespace Engine {
		class Primitive;

		class CmptGeometry : public Component {
			COMPONENT_SETUP(CmptGeometry)
		public:
			CmptGeometry(Basic::Ptr<SObj> sobj, Basic::Ptr<Primitive> primitive)
				: Component(sobj), primitive(primitive) { }

		public:
			Basic::Ptr<Primitive> primitive;
		};
	}
}

#endif//!_ENGINE_COMPONENT_CMPT_GEOMETRY_H_