using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    [SerializeField]
    private float PlayerSpeed = 5.0f;

    private Vector3 TargetPoint;

    private bool isMove = false;

    private Camera mainCamra;

    private void Start()
    {
        mainCamra = Camera.main;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetMouseButton(0))
        {
            RaycastHit hit;
            if (Physics.Raycast(mainCamra.ScreenPointToRay(Input.mousePosition), out hit))
            {
                TargetPoint = new Vector3(hit.point.x, transform.position.y, transform.position.z);
                isMove = true;
            }
        }

        if (isMove)
        {
            transform.position = Vector3.MoveTowards(
                transform.position, 
                TargetPoint, 
                PlayerSpeed * Time.deltaTime);

            if(transform.position == TargetPoint)
            {
                isMove = false;
            }
        }
    }
}
