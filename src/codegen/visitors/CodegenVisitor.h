#pragma once 

#include "../../ast/ASTVisitor.h"
#include "../context/CodegenContext.h"
#include "../../ast/Nodes.h"


namespace umbra{
    namespace code_gen{


        class CodegenVisitor : public BaseVisitor {
        public:
            CodegenVisitor(CodegenContext &context);

            llvm::Type* mapBuiltinTypeToLLVMType(const umbra::Type& type) const;
            std::string createFormatStringSpecifier(llvm::Type* type);
            //umbra::Type* mapLLVMTypeToBuiltinType(llvm::Type* type) const;

            //program
            void visit(umbra::ProgramNode& node) override;

            //literals
            void visit(umbra::StringLiteral& node) override;
            void visit(umbra::NumericLiteral& node) override;
            void visit(umbra::BooleanLiteral& node) override;
            void visit(umbra::CharLiteral& node) override;

            //expressions
            void visit(umbra::ExpressionStatement& node) override;
            void visit(umbra::PrimaryExpression& node) override;

            //statements
            void visit(umbra::FunctionCall& node) override;
            void visit(umbra::RepeatTimesStatement& node) override;
            void visit(umbra::RepeatIfStatement& node) override;

            //top_level
            void visit(umbra::FunctionDefinition& node) override;
            void visit(umbra::VariableDeclaration& node) override;
            void visit(umbra::AssignmentStatement& node) override;

            //auxiliar

            llvm::Value* getLastValue() const;


            private: 
            llvm::Value* lastLLVMValue = nullptr;
            CodegenContext& context;

        };
    }
}