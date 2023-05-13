import PyRxApp
import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import io
import pydoc


def PyRxCmd_pydoit():
	try:
		doc_content = io.StringIO()
		helper = pydoc.Helper(output=doc_content)
		helper.help(Db)

		with open('PyDb.HTML', mode='w') as f:
			print(doc_content.getvalue(), file=f)

	except Exception as err:
		PyRxApp.Printf(err)
