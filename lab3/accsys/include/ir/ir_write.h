#include "ir/type.h"
#include "ir/ir.h"
#include "utils/casting.h"

#include <stdexcept>
#include <ostream>


enum PrefixType {
    GlobalPrefix,
    ArgPrefix,
    LocalPrefix,
    NoPrefix
};

class ListSeparator {
    std::string_view Seperator;
    bool FirstItem = true;
public:
    ListSeparator(std::string_view Separator = ", ") : Seperator(Separator) {}
    ~ListSeparator() = default;
    operator std::string_view()  {
        if (FirstItem) {
            FirstItem = false;
            return {};
        } else {
            return Seperator;
        }
    }
};


namespace {

class TypePrinter {
public:
    void print(Type *Ty, std::ostream &os);
};

} // end of annoymous namespace

/// Assign the slot number to annoymous values
class SlotTracker {
    const Module *M;

    // Global scope slots.
    std::unordered_map<Function *, unsigned> FunctionSlots;
    std::unordered_map<GlobalVariable *, unsigned> GlobalSlots;
    unsigned gNext = 0;
    // Local scope slots, binding to a specific function.
    Function *F;
    std::unordered_map<BasicBlock *, unsigned> BasicBlockSlots;
    std::unordered_map<Value *, unsigned> LocalSlots;
    unsigned lNext = 0;

public:

    explicit SlotTracker(const Module *M);

    void incorporateFunction(const Function *F);

    std::optional<unsigned> getGlobalSlot(const GlobalVariable *GV);
    std::optional<unsigned> getFunctionSlot(const Function *F);

    std::optional<unsigned> getBasicBlockSlot(const BasicBlock *BB);
    std::optional<unsigned> getLocalSlot(const Value *V);
};

/// Print the Accipit IR to text form.
class AccipitWriter {
    std::ostream &Out;
    SlotTracker &Tracker;
    bool isForDebug;
public:
    AccipitWriter(std::ostream &OS, SlotTracker &Tracker, bool isForDebug)
        : Out(OS), Tracker(Tracker), isForDebug(isForDebug) { }

    void printInstruction(const Instruction *I);
    void printBasicBlock(const BasicBlock *BB);
    void printArgument(const Argument *Arg);
    void printFunction(const Function *F);
    void printGlobalVariable(const GlobalVariable *GV);
    void printModule(const Module *M);
};

/// Turn the specified name into an 'Accipit name', which is either prefixed with %
static void PrintAccipitName(std::ostream &OS, std::string_view Name, PrefixType Prefix);

/// Turn the specified name into an 'Accipit name', which is either prefixed with %
static void PrintAccipitName(std::ostream &OS, const Value *V);


static void WriteConstantInternal(std::ostream &Out, const Constant *C,
                                  SlotTracker &Tracker, bool isForDebug);

// Full implementation of printing a Value as an operand with support for
// TypePrinting, etc.
static void WriteAsOperandInternal(std::ostream &Out, const Value *V,
                                   SlotTracker &Tracker, bool isForDebug);

static void WriteFunctionOperandInternal(std::ostream &Out, const Function *F,
                                        SlotTracker &Tracker, bool isForDebug);

static void WriteBasicBlockOperandInternal(std::ostream &Out, const BasicBlock *BB,
                                          SlotTracker &Tracker, bool isForDebug);
