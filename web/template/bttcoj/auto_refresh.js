judge_result=Array("等待","等待重判","编译中","运行并评判","答案正确","格式错误","答案错误","时间超限","内存超限",
"输出超限","运行错误","编译错误","运行错误(点击看详细)","编译错误(点击看详细)","编译成功","点击看详细","人工判题");
judge_icon = Array(
			"<i class=\"hourglass half icon\"></i>", 
			"<i class=\"hourglass half icon\"></i>", 
			"<i class=\"spinner icon\"></i>", 
			"<i class=\"spinner icon\"></i>", 
			"<i class=\"checkmark icon\"></i>", 
			"<i class=\"server icon\"></i>", 
			"<i class=\"remove icon\"></i>", 
			"<i class=\"clock icon\"></i>", 
			"<i class=\"microchip icon\"></i>", 
			"<i class=\"print icon\"></i>", 
			"<i class=\"bomb icon\"></i>", 
			"<i class=\"code icon\"></i>",
			"<i class=\"ban icon\"></i>", 
			"<i class=\"file outline icon\"></i>", 
			"<i class=\"server icon\"></i>", 
			"<i class=\"folder open outline icon\"></i>", 
			"<i class=\"minus icon\"></i>", 
			"<i class=\"ban icon\"></i>"
		  );
judge_style=Array("waiting",
		  "status waiting",
		  "status compiling",
		  "status running",
		  "status accepted",
		  "status judgement_failed",
		  "status wrong_answer",
		  "status time_limit_exceeded",
		  "status memory_limit_exceeded",
		  "status output_limit_exceeded",
		  "status runtime_error",
		  "status compile_error",
		  
		  "status invalid_interaction",
		  "status file_error",
		  "status system_error",
		  "status no_testdata",
		  "status partially_correct",
		  "status skipped");




var i=0;
var interval=300;
function auto_refresh(){
	interval=300;
	var tb=window.document.getElementById('vueAppFuckSafari');
	var rows=tb.rows;
	for(var i=rows.length-1;i>0;i--){
		var result=$(rows[i].cells[3].children[0].innerHTML).attr("result");
		var sid=rows[i].cells[0].children[0].innerHTML;
		if(result<4){
			//alert(sid);
			window.setTimeout("fresh_result("+sid+")",interval);
			console.log("auto_refresh "+sid+" actived!");
		}
	}
}
function findRow(solution_id){
	var tb=window.document.getElementById('vueAppFuckSafari');
	var rows=tb.rows;
	for(var i=1;i<rows.length;i++){
		var cell=rows[i].cells[0].children[0];
		if(cell.innerHTML==solution_id) return rows[i];
	}
}

function fresh_result(solution_id){
	var xmlhttp;
	if (window.XMLHttpRequest){// code for IE7+, Firefox, Chrome, Opera, Safari
		xmlhttp=new XMLHttpRequest();
	}else{// code for IE6, IE5
		xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.onreadystatechange=function(){
		if (xmlhttp.readyState==4 && xmlhttp.status==200)
		{
			var tb=window.document.getElementById('vueAppFuckSafari');
			var row=findRow(solution_id);
			//alert(row.innerHTML);
			var r=xmlhttp.responseText;
			var ra=r.split(",");
			//alert(r);
			// alert(judge_result[r]);
			
			//alert(ra[0]);
			if(ra[0]<4){
			//	console.log(loader);
				//row.cells[3].innerHTML=ra[0];
				//alert("<span class=\""+judge_style[ra[0]]+"\">"+judge_icon[ra[0]]+judge_result[ra[0]]+"</span>");
				row.cells[3].innerHTML="<span class='hidden' style='display:none' result='"+ra[0]+"' ></span><b><span class=\""+judge_style[ra[0]]+"\">"+judge_icon[ra[0]]+judge_result[ra[0]]+"</span></b>";
				row.cells[4].innerHTML="<b>---</b>";
				row.cells[5].innerHTML="<b>---</b>";
				row.cells[9].innerHTML="<b>"+ra[3]+"</b>";
				window.setTimeout("fresh_result("+solution_id+")",interval);
				//interval*=2;
			}else
			{
				row.cells[3].innerHTML="<span class='hidden' style='display:none' result='"+ra[0]+"' ></span><b><span class=\""+judge_style[ra[0]]+"\">"+judge_icon[ra[0]]+judge_result[ra[0]]+"</span></b>";
				//<span class='hidden' style='display:none' result='".$row['result']."' ></span>
				//"<span class='".$judge_style[$row['result']]+"'  title='$MSG_Tips'>*"+$judge_icon[$row['result']].$judge_result[$row['result']]+"</span>";
				//"";

				//alert(ra[0]);
				/*switch(ra[0]){
				 case "6":
				 case "10":
					//row.cells[3].innerHTML="<a href='reinfo.php?sid="+solution_id+"' class='"+judge_color[ra[0]]+"'>"+judge_result[ra[0]]+"</a>";
					//row.cells[3].innerHTML="<span class='hidden' style='display:none' result='"+ra[0]+"' ></span>";
					//row.cells[3].innerHTML+="<span class='"+judge_style[ra[0]]+">"+judge_icon[ra[0]]+judge_result[ra[0]]+"</span>";

					break;
				 case "11":
					//row.cells[3].innerHTML="<a href='ceinfo.php?sid="+solution_id+"' class='"+judge_color[ra[0]]+"'>"+judge_result[ra[0]]+"</a>";
					row.cells[3].innerHTML=ra[0];
					break;
				
				  default:
				  	row.cells[3].innerHTML=ra[0];
					//row.cells[3].innerHTML="<span class='"+judge_color[ra[0]]+"'>"+judge_result[ra[0]]+"</span>";
				}*/
				row.cells[4].innerHTML="<b>"+ra[1]+"KB</b>";
				row.cells[5].innerHTML="<b>"+ra[2]+"MS</b>";
				row.cells[9].innerHTML="<b>"+ra[3]+"</b>";
				auto_refresh();
                
			}
		}
	}
	xmlhttp.open("GET","status-ajax.php?solution_id="+solution_id,true);
	xmlhttp.send();
}
// var hj_ss="<select class='http_judge form-control' length='2' name='result'>";
// 	for(var i=0;i<10;i++){
//    		hj_ss+="	<option value='"+i+"'>"+judge_result[i]+" </option>";
// 	}
//    hj_ss+="</select>";
//    hj_ss+="<input name='manual' type='hidden'>";
//    hj_ss+="<input class='http_judge form-control' size=5 title='输入判定原因与提示' name='explain' type='text'>";
//    hj_ss+="<input type='button' class='http_judge btn' name='manual' value='确定' onclick='http_judge(this)' >";
// $(".http_judge_form").append(hj_ss);
// auto_refresh();
// $(".td_result").mouseover(function (){
// //   $(this).children(".btn").hide(300);
//    $(this).find("form").show(600);
//    var sid=$(this).find("span[class=original]").attr("sid");
//    $(this).find("span[class=original]").load("status-ajax.php?q=user_id&solution_id="+sid);
// });
// $(".http_judge_form").hide();

// function http_judge(btn){
//    var sid=$(btn).parent()[0].children[0].value;
//    $.post("admin/problem_judge.php",$(btn).parent().serialize(),function(data,textStatus){
//    		if(textStatus=="success")window.setTimeout("fresh_result("+sid+")",1000);
// 	})
//    return false;
// }
auto_refresh();