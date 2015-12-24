#include "classdefinitionnode.hpp"
#include "../runtime/stdclass.hpp"
#include "../context.hpp"
#include "nodes.hpp"
#include <iostream>

//
// TODO: There's sometimes a bug when having two class definitions in a row
// Doesn't occure often, debug later.
//
Nodes::ClassDefinitionNode::ClassDefinitionNode(std::string name, std::string superName, AbstractNode *body)
{
  this->name      = name;
  this->superName = superName;
  this->body      = (Nodes::Nodes*)body;
}

Runtime::Object*
Nodes::ClassDefinitionNode::eval(Context *context)
{
  Runtime::StdClass *klass;
  Nodes::Nodes *nodes = (Nodes::Nodes*)this->body;

  // the default superclass is Object
  if(this->superName.empty())
  {

    klass = new Runtime::StdClass(this->name,
      (Runtime::StdClass*)context->getCurrentClass()->getConstant(std::string("Object"))
    );
    //
    // TODO: There's a bug with Lang::Runtime::getRootClass(....)
    // the constructor should make a call to the "Class" class, but throws a segment error
    // quick workaround for the time being
    //
    klass->setStdClass(klass);
  }
  else
  {
    Runtime::StdClass *superClass = (Runtime::StdClass*)context->getCurrentClass()->getConstant(this->superName);
    superClass->setStdClass(superClass);
    klass = new Runtime::StdClass(this->name, superClass);
    klass->setStdClass(klass);
  }

  Context *eval_context = new Context(klass, klass);
  for(int i = 0; i < nodes->nodes.size(); i++)
  {
    nodes->nodes[i]->eval(eval_context);
  }

  // register the new class as a constant
  context->getCurrentClass()->setConstant(name, klass);

  return klass;
}