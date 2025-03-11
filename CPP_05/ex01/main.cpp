#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	Marc_Dutroux = Bureaucrat("Marc_Dutroux", 3);
	Bureaucrat	Marc_Dutroux_copy = Marc_Dutroux;
	Bureaucrat	Émile_Louis = Bureaucrat("Émile_Louis", 150);
	Bureaucrat	lou = Bureaucrat("Kevin", 20);

	Form		f1 = Form("f1", 75, 1);
	Form		f2 = Form("f2", 2, 1);
	Form		f3 = Form("f3", 20, 1);

	std::cout << "Create a form with incorect grade: ";
	try
	{
		Form	f4 = Form("f4", 0, 184);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "SignForm: Émile_Louis sign F1: ";
	try
	{
		Émile_Louis.signForm(f1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "BeSigned: Marc_Dutroux sign F2: ";
	try
	{
		f2.beSigned(Marc_Dutroux);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Marc_Dutroux_copy.incrementGrade();

	std::cout << "BeSigned: Thierry_copy sign F2: ";
	try
	{
		f2.beSigned(Marc_Dutroux_copy);
		std::cout << "OK" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "SignForm: Kevin sign F3: ";
	try
	{
		lou.signForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
